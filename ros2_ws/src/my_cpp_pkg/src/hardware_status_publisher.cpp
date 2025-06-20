#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class HardwareStatusPublisherNode : public rclcpp::Node
{
public:
    HardwareStatusPublisherNode() : Node("hardware_status_publisher")
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_status", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&HardwareStatusPublisherNode::callbackTimer, this));
        RCLCPP_INFO(this->get_logger(), "hardware_status node has been started");
    }
private:
    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void callbackTimer()
    {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temperature = 113.1;
        msg.are_motors_ready = true;
        msg.debug_message = "There will be blood...sheed";
        publisher_->publish(msg);
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}