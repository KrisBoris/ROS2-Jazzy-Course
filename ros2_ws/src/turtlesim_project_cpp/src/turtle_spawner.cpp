#include "rclcpp/rclcpp.hpp"
#include "turtlesim_project_interfaces/msg/spawned_turtle.hpp"
#include "turtlesim/srv/spawn.hpp"
#include "turtlesim/srv/kill.hpp"
#include "std_msgs/msg/string.hpp"
#include "cstdlib.hpp"
#include "ctime"

class TurtleSpawnerNode : public rclcpp::Node
{
public:
    TurtleSpawnerNode() : Node("turtle_spawner")
    {
        this->declare_parameter("spawn_pace", 5.0);
        __spawnPace = this->get_parameter("spawn_pace").as_double();

        __clientSpawn = this->create_client<turtlesim::srv::Spawn>("spawn");
        __clientKill = this->create_client<turtlesim::srv::Kill>("kill");
        __publisherSpawnedTurtle = this->create_publisher<turtlesim_project_interfaces::msg::SpawnedTurtle>("spawned_turtle", 10);
        __subscriberKilledTurtle = this->create_subscription<std_msgs::msg::String>("killed_turtle", 10,
            std::bind(&TurtleSpawnerNode::callbackSubscriptionKilledTurtle, this, std::placeholders::_1));
        __timerSpawnTurtle = this->create_wall_timer(std::chrono::duration<double>(__spawnPace), 
            std::bind(&TurtleSpawnerNode::callbackTimerSpawnTurtle, this));

        srand(time(0));
    }    

    void callbackSubscriptionKilledTurtle(std_msgs::msg::String name)
    {

    }

    void callbackTimerSpawnTurtle()
    {
        while(!__clientSpawn->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_INFO(this->get_logger(), "Standing here...");
        }

        auto spawnedTurtle = std::make_shared<turtlesim::srv::Spawn::Request>();
        spawnedTurtle->x = __randomDouble();
        spawnedTurtle->y = __randomDouble();

        __clientSpawn->async_send_request(spawnedTurtle, [this, spawnedTurtle](rclcpp::Client<turtlesim::srv::Spawn>::SharedFuture future) {
            this->callbackServiceSpawnedTurtle(future, spawnedTurtle);
        });         
    }    

    void callbackServiceSpawnedTurtle(rclcpp::Client<turtlesim::srv::Spawn>::SharedFuture future, 
        turtlesim::srv::Spawn::Request::SharedPtr request)
    {
        auto response = future.get();

        auto spawnedTurtle = turtlesim_project_interfaces::msg::SpawnedTurtle();
        spawnedTurtle.name = response->name;
        spawnedTurtle.pose.x = request->x;
        spawnedTurtle.pose.y = request->y;    
        
        __publisherSpawnedTurtle->publish(spawnedTurtle);

        RCLCPP_INFO(this->get_logger(), "Turtle %s has been spawned", response->name);
    }

private:
    rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr __clientSpawn;
    rclcpp::Client<turtlesim::srv::Kill>::SharedPtr __clientKill;
    rclcpp::Publisher<turtlesim_project_interfaces::msg::SpawnedTurtle>::SharedPtr __publisherSpawnedTurtle;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr __subscriberKilledTurtle;
    rclcpp::TimerBase::SharedPtr __timerSpawnTurtle;
    double __spawnPace;

    double __randomDouble()
    {
        // Returns value from 0.0 to 10.0        
        return (double)(rand() % 10001) / 1000.0;
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleSpawnerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}