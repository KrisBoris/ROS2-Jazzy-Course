#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberPublisherNode : public rclcpp::Node
{
public:
    NumberPublisherNode() : Node("number_publisher")
    {               
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(2), std::bind(&NumberPublisherNode::callbackPublish, this));
        number_ = 2;
        RCLCPP_INFO(this->get_logger(), "number_publisher node has been started");
    }
private:        
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int number_;

    void callbackPublish()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        publisher_->publish(msg);
    }
};

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}