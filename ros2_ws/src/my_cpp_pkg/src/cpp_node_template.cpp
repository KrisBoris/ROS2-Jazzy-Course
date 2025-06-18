#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node  // Change name
{
public:
    MyNode() : Node("cpp_test")    // Change names
    {                
    }
private:    
};

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();    // Change name
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}