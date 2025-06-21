#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"

class BatteryMonitorNode : public rclcpp::Node
{
public:
    BatteryMonitorNode() : Node("battery_monitor_node")
    {
        batteryState_ = 0;
        client_ = this->create_client<my_robot_interfaces::srv::SetLed>("set_led");   
        shortTimer_ = this->create_wall_timer(std::chrono::seconds(4), 
            std::bind(&BatteryMonitorNode::callbackShortTimer, this));
        longTimer_ = this->create_wall_timer(std::chrono::seconds(6), 
            std::bind(&BatteryMonitorNode::callbackLongTimer, this));
    }
private:
    bool batteryState_;  // 0 = empty, 1 = full
    rclcpp::Client<my_robot_interfaces::srv::SetLed>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr shortTimer_;
    rclcpp::TimerBase::SharedPtr longTimer_;

    void callbackShortTimer()
    {   
        batteryState_ = 0;

        while(!client_->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_INFO(this->get_logger(), "Standing here...");
        }

        auto request = std::make_shared<my_robot_interfaces::srv::SetLed::Request>();
        request->led_number = 3;
        request->led_status = batteryState_;
        
        client_->async_send_request(request, std::bind(&BatteryMonitorNode::callbackClient, this,
            std::placeholders::_1));

        // Stop 4 seconds timer
        shortTimer_->cancel();
        // Start 6 seconds timer
        longTimer_->reset();
    }

    void callbackLongTimer()
    {
        batteryState_ = 1;
    }

    void callbackClient(rclcpp::Client<my_robot_interfaces::srv::SetLed>::SharedFuture future)
    {

    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BatteryMonitorNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}