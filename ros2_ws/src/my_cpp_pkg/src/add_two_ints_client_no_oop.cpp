#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"


int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<rclcpp::Node>("add_two_ints_no_oop");    
    auto client_ = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    while(!client_->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_INFO(node->get_logger(), "Standing here...");
    }    
    
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 9;
    request->b = 7;
    
    auto future = client_->async_send_request(request);
    rclcpp::spin_until_future_complete(node, future);

    auto result = future.get();
    RCLCPP_INFO(node->get_logger(), "%d + %d = %d", (int)request->a, (int)request->b, (int)result->sum);

    rclcpp::shutdown();
    return 0;
}