#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsServerNode : public rclcpp::Node
{
public:
    AddTwoIntsServerNode() : Node("add_two_ints")
    {                
        service_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", 
            std::bind(&AddTwoIntsServerNode::callbackService, this, std::placeholders::_1, std::placeholders::_2));
        RCLCPP_INFO(this->get_logger(), "add_two_ints_service has been started");
    }
private:    
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;

    void callbackService(example_interfaces::srv::AddTwoInts::Request::SharedPtr request, 
        example_interfaces::srv::AddTwoInts::Response::SharedPtr response)
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "%d + %d = %d", (int)request->a, (int)request->b, (int)response->sum);
    }
};

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}