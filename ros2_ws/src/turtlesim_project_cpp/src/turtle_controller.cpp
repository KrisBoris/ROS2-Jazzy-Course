#include "rclcpp/rclcpp.hpp"
#include "turtlesim_project_interfaces/msg/spawned_turtle.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/string.hpp"
#include "turtlesim/msg/pose.hpp"

// ToDo:
// When turtle is in theta close to 0.0 it cannot decide which way should he turn

class TurtleControllerNode : public rclcpp::Node
{
public:
    TurtleControllerNode() : Node("turtle_controller")
    {
        __publisherVelocity = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        __publisherKilledTurtle = this->create_publisher<std_msgs::msg::String>("killed_turtle", 10);
        __subscriberTurtlePosition = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, 
            std::bind(&TurtleControllerNode::callbackSubscriptionTurtlePosition, this, std::placeholders::_1));
        __subscriberSpawnedTurtle = this->create_subscription<turtlesim_project_interfaces::msg::SpawnedTurtle>("spawned_turtle", 10,
            std::bind(&TurtleControllerNode::callbackSubscriptionSpawnedTurtle, this, std::placeholders::_1));                       

        RCLCPP_INFO(this->get_logger(), "turtle_controller has been created");
    }

    void callbackSubscriptionTurtlePosition(turtlesim::msg::Pose position)
    {        
        if(!__spawnedTurtles.empty())
        {
            if(abs(__spawnedTurtles[0].pose.x - position.x) < TURTLES_DISTANCE && abs(__spawnedTurtles[0].pose.y - position.y) < TURTLES_DISTANCE)
            {
                publishTurtleKilled(__spawnedTurtles[0].name);
                __spawnedTurtles.erase(__spawnedTurtles.begin());
            }
            else
            {                                   
                auto cmdVel = geometry_msgs::msg::Twist();                

                double xVec = __spawnedTurtles[0].pose.x - position.x;
                double yVec = __spawnedTurtles[0].pose.y - position.y;
                double angle = std::atan2(yVec, xVec);

                RCLCPP_INFO(this->get_logger(), "angle: %f", angle);
                RCLCPP_INFO(this->get_logger(), "theta: %f", position.theta);    
                
                double oppositeThetaAngle = __calcOppositeAngle(position.theta);

                if(abs(position.theta - angle) < ANGLES_ALIGNMENT)
                {
                    // Move forward
                    cmdVel.linear.x = FORWARD_SPEED;
                    RCLCPP_INFO(this->get_logger(), "forward speed");
                }
                else if((angle > position.theta && (position.theta >= 0 || angle < oppositeThetaAngle))
                    || (angle < position.theta && angle < oppositeThetaAngle))
                {
                    // Turn left (anticlockwise)
                    cmdVel.angular.z = TURNING_LEFT_SPEED;
                    cmdVel.linear.x = FORWARD_TURNING_SPEED;
                    RCLCPP_INFO(this->get_logger(), "turning left");   
                }  
                else
                {
                    // Turn right (clockwise)
                    cmdVel.angular.z = TURNING_RIGHT_SPEED;
                    cmdVel.linear.x = FORWARD_TURNING_SPEED;
                    RCLCPP_INFO(this->get_logger(), "turning right");
                }                                
                                
                __publisherVelocity->publish(cmdVel);
            }
        }        
    }

    void callbackSubscriptionSpawnedTurtle(turtlesim_project_interfaces::msg::SpawnedTurtle spawnedTurtle)
    {
        __spawnedTurtles.push_back(spawnedTurtle);
    }

    void publishTurtleKilled(std::string name)
    {
        auto killedTurtle = std_msgs::msg::String();
        killedTurtle.data = name;        

        __publisherKilledTurtle->publish(killedTurtle);
    }

private:
    static constexpr double TURTLES_DISTANCE = 0.3;
    static constexpr double FORWARD_SPEED = 2.0;
    static constexpr double FORWARD_TURNING_SPEED = 0.5;
    static constexpr double TURNING_LEFT_SPEED = 2.0;
    static constexpr double TURNING_RIGHT_SPEED = -2.0;
    static constexpr double ANGLES_ALIGNMENT = 0.1;
    static constexpr double PI = 3.14159;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr __publisherVelocity;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr __publisherKilledTurtle;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr __subscriberTurtlePosition;
    rclcpp::Subscription<turtlesim_project_interfaces::msg::SpawnedTurtle>::SharedPtr __subscriberSpawnedTurtle;

    std::vector<turtlesim_project_interfaces::msg::SpawnedTurtle> __spawnedTurtles;    

    double __calcOppositeAngle(double angle)
    {
        if(angle > 0)
        {
            return angle - PI;
        }
        else 
        {
            return angle + PI;
        }
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}