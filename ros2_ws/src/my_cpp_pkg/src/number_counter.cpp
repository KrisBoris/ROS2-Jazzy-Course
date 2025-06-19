#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberCounterNode : public rclcpp::Node
{
public:
    NumberCounterNode() : Node("number_count")
    {                
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>("number", 10, 
            std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        counter_ = 0;
        RCLCPP_INFO(this->get_logger(), "number_count node has been started");
    }
private:
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    int counter_;        

    void callbackNumber(example_interfaces::msg::Int64 number)
    {
        auto msg = example_interfaces::msg::Int64();
        counter_ += number.data;
        msg.data = counter_;
        publisher_->publish(msg);
    }
};

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}