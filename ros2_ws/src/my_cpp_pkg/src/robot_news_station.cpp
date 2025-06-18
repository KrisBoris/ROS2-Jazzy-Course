#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class RobotNewsStationNode : public rclcpp::Node  // Change name
{
public:
    RobotNewsStationNode() : Node("robot_news_station")    // Change names
    {                
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer_ = this->create_wall_timer(1s, std::bind(&RobotNewsStationNode::publishNews, this));
        RCLCPP_INFO(this->get_logger(), "Robot News Station has started");
    }
private:   
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string message = "Hello there";

    void publishNews()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = std::string(message);
        publisher_->publish(msg);
    }
};

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>();    // Change name
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}