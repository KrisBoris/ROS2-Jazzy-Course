#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/set_bool.hpp"


class ResetCounterNode : public rclcpp::Node
{
public:
    ResetCounterNode() : Node("reset_counter")
    {
        client_ = this->create_client<example_interfaces::srv::SetBool>("reset_counter");
        timer_ = this->create_wall_timer(std::chrono::seconds(10), std::bind(&ResetCounterNode::callbackTimer, this));
        waitingForServiceCounter_ = 0;
        RCLCPP_INFO(this->get_logger(), "reset_counter node has been started");
    }

private:
    rclcpp::Client<example_interfaces::srv::SetBool>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string waitingForServiceCalls_[12] = {"Standing here", "I realized", "You were just like me", "Trying to make history", 
        "But who's to judge", "the right from wrong?", "When our guard is down", "I think we'll both agree", "That violence", "breeds violence",
        "But in the end", "it has to be this way"};
    int waitingForServiceCounter_;

    void callbackTimer()
    {
        while(!client_->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_INFO(this->get_logger(), "%s", waitingForServiceCalls_[waitingForServiceCounter_].c_str());
            waitingForServiceCounter_++;
            if(waitingForServiceCounter_ >= 12)
            {
                waitingForServiceCounter_ = 0;
            }
        }

        auto request = std::make_shared<example_interfaces::srv::SetBool::Request>();
        request->data = true;

        client_->async_send_request(request, std::bind(&ResetCounterNode::callbackService, this, std::placeholders::_1));
    }

    void callbackService(rclcpp::Client<example_interfaces::srv::SetBool>::SharedFuture future)
    {
        auto response = future.get();
        RCLCPP_INFO(this->get_logger(), "%s", response->message.c_str());
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ResetCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}