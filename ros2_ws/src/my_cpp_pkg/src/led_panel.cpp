#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/led_panel_state.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"

class LedPanelNode : public rclcpp::Node
{
public:
    LedPanelNode() : Node("led_panel")
    {        
        this->declare_parameter("led_states", std::vector<bool>{false, false, false});

        ledPanelState = this->get_parameter("led_states").as_bool_array();
        service_ = this->create_service<my_robot_interfaces::srv::SetLed>("set_led", 
            std::bind(&LedPanelNode::callbackService, this, std::placeholders::_1, std::placeholders::_2));
        publisher_ = this->create_publisher<my_robot_interfaces::msg::LedPanelState>("led_panel_state", 10);    
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&LedPanelNode::callbackTimer, this));    
        RCLCPP_INFO(this->get_logger(), "led_panel has been started");
    }
private:    
    std::vector<bool> ledPanelState;
    rclcpp::Service<my_robot_interfaces::srv::SetLed>::SharedPtr service_;
    rclcpp::Publisher<my_robot_interfaces::msg::LedPanelState>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void callbackService(my_robot_interfaces::srv::SetLed::Request::SharedPtr request, 
        my_robot_interfaces::srv::SetLed::Response::SharedPtr response)
    {
        ledPanelState[request->led_number - 1] = request->led_status;
        response->success = true;
    }

    void callbackTimer()
    {
        auto msg = my_robot_interfaces::msg::LedPanelState();
        for(int i = 0; i < 3; i++)
        {
            msg.led_status[i] = ledPanelState[i];
        }
        publisher_->publish(msg);
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LedPanelNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}