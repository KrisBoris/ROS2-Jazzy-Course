#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberPublisherNode : public rclcpp::Node
{
public:
    NumberPublisherNode() : Node("number_publisher")
    {               
        this->declare_parameter("number", 2);
        this->declare_parameter("timer_period", 2.0);
        number_ = this->get_parameter("number").as_int();
        double timer_period = this->get_parameter("timer_period").as_double();

        param_callback_handle_ = this->add_post_set_parameters_callback(
            std::bind(&NumberPublisherNode::callbackParameters, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        timer_ = this->create_wall_timer(std::chrono::duration<double>(timer_period), std::bind(&NumberPublisherNode::callbackPublish, this));        
        RCLCPP_INFO(this->get_logger(), "number_publisher node has been started");
    }
private:        
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    PostSetParametersCallbackHandle::SharedPtr param_callback_handle_;
    int number_;

    void callbackPublish()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        publisher_->publish(msg);
    }

    void callbackParameters(const std::vector<rclcpp::Parameter> & params)
    {
        for(const auto &param : params)
        {
            if(param.get_name() == "number") {
                number_ = param.as_int();
            }
        }
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