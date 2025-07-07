#include "rclcpp/rclcpp.hpp"
#include "turtlesim_project_interfaces/msg/spawned_turtle.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/string.hpp"
#include "turtlesim/msg/pose.hpp"

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
            
        prevXDistance = 0.0;
        prevYDistance = 0.0;

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
                // Measure distance and previous distance from turtle to the target
                // Based on differences betweem current x and y and previous one decide in which quarter, relatively
                // to the turtle is the target based
                // Using that choose the turn 

                auto cmd_vel = geometry_msgs::msg::Twist();
                
                double xSignedDistance = __spawnedTurtles[0].pose.x - position.x;
                double ySignedDistance = __spawnedTurtles[0].pose.y - position.y;

                double xDistance = abs(xSignedDistance);
                double yDistance = abs(ySignedDistance);

                RCLCPP_INFO(this->get_logger(), "X position: %f", position.x);
                RCLCPP_INFO(this->get_logger(), "Y position: %f", position.y);
                
                RCLCPP_INFO(this->get_logger(), "X distance: %f", xDistance);
                RCLCPP_INFO(this->get_logger(), "Y distance: %f", yDistance);

                RCLCPP_INFO(this->get_logger(), "prev X distance: %f", prevXDistance);
                RCLCPP_INFO(this->get_logger(), "prev Y distance: %f", prevYDistance);                
                
                if(xDistance <= prevXDistance && yDistance <= prevYDistance)
                {
                    // Target is in the first quarter
                    
                    if(xDistance > yDistance + DISTANCE_MARGIN)
                    {
                        if((xSignedDistance > 0 && ySignedDistance > 0) || (xSignedDistance < 0 && ySignedDistance < 0))
                        {
                            // Turn right (clockwise)
                            cmd_vel.angular.z = TURNING_RIGHT_SPEED;  
                            cmd_vel.linear.x = FORWARD_TURNING_SPEED; 
                        }
                        else
                        {
                            // Turn left (anticlockwise)
                            cmd_vel.angular.z = TURNING_LEFT_SPEED;  
                            cmd_vel.linear.x = FORWARD_TURNING_SPEED; 
                        }
                                             
                    }
                    else if(xDistance < yDistance - DISTANCE_MARGIN)
                    {
                        if((xSignedDistance > 0 && ySignedDistance > 0) || (xSignedDistance < 0 && ySignedDistance < 0))
                        {
                            // Turn left (anticlockwise)
                            cmd_vel.angular.z = TURNING_LEFT_SPEED;
                            cmd_vel.linear.x = FORWARD_TURNING_SPEED;
                        }   
                        else
                        {
                            // Turn right (clockwise)
                            cmd_vel.angular.z = TURNING_RIGHT_SPEED;  
                            cmd_vel.linear.x = FORWARD_TURNING_SPEED; 
                        }                     
                    }
                    else
                    {
                        // Only move forward
                        cmd_vel.linear.x = FORWARD_SPEED;
                    }                    
                }                
                else if(xDistance > prevXDistance && yDistance < prevYDistance)
                {
                    // Target is in the second quarter (anticlockwise)
                    // Keep turnign left (anticlockwise) until target would be in the first quarter
                    cmd_vel.angular.z = TURNING_LEFT_SPEED;
                    cmd_vel.linear.x = FORWARD_TURNING_SPEED;                    
                }                
                else if(xDistance > prevXDistance && yDistance > prevYDistance)
                {
                    // Target is in the third quarter (anticlockwise) 
                    
                    if(xDistance < yDistance)
                    {
                        // Turn right (clockwise)       
                        cmd_vel.angular.z = TURNING_RIGHT_SPEED;
                        cmd_vel.linear.x = FORWARD_TURNING_SPEED;                 
                    }
                    else 
                    {
                        // Turn left (anticlockwise)
                        cmd_vel.angular.z = TURNING_LEFT_SPEED;
                        cmd_vel.linear.x = FORWARD_TURNING_SPEED;
                    }
                }                
                else if(xDistance < prevXDistance && yDistance > prevYDistance)
                {
                    // Target is in the fourth quarter (anticlockwise)                     
                    // Keep turnign right (clockwise) until target would be in the first quarter
                    cmd_vel.angular.z = TURNING_RIGHT_SPEED ;
                    cmd_vel.linear.x = FORWARD_TURNING_SPEED;
                }                
                
                prevXDistance = xDistance;
                prevYDistance = yDistance;

                __publisherVelocity->publish(cmd_vel);
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
    static constexpr double DISTANCE_MARGIN = 0.0;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr __publisherVelocity;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr __publisherKilledTurtle;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr __subscriberTurtlePosition;
    rclcpp::Subscription<turtlesim_project_interfaces::msg::SpawnedTurtle>::SharedPtr __subscriberSpawnedTurtle;

    std::vector<turtlesim_project_interfaces::msg::SpawnedTurtle> __spawnedTurtles;

    double prevXDistance;
    double prevYDistance;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}