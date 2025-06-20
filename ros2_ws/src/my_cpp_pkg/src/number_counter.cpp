#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

class NumberCounterNode : public rclcpp::Node
{
public:
    NumberCounterNode() : Node("number_count")
    {                
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>("number", 10, 
            std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        service_ = this->create_service<example_interfaces::srv::SetBool>("reset_counter", 
            std::bind(&NumberCounterNode::callbackService, this, std::placeholders::_1, std::placeholders::_2));                
        counter_ = 0;
        RCLCPP_INFO(this->get_logger(), "number_count node has been started");
    }
private:
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr service_;
    int counter_;        

    void callbackNumber(example_interfaces::msg::Int64 number)
    {
        auto msg = example_interfaces::msg::Int64();
        counter_ += number.data;
        msg.data = counter_;
        publisher_->publish(msg);
    }    

    void callbackService(example_interfaces::srv::SetBool::Request::SharedPtr request,
        example_interfaces::srv::SetBool::Response::SharedPtr response)
    {
        if(request->data)
        {
            counter_ = 0;
            response->message = "Counter has been reseted";            
        }
        else 
        {
            response->message = "Counter was not reseted";            
        }
        response->success = true;        
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