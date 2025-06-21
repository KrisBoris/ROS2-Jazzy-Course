// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/CalculateRectangleArea.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/srv/calculate_rectangle_area.hpp"


#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/calculate_rectangle_area__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_CalculateRectangleArea_Request_width
{
public:
  explicit Init_CalculateRectangleArea_Request_width(::my_robot_interfaces::srv::CalculateRectangleArea_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::CalculateRectangleArea_Request width(::my_robot_interfaces::srv::CalculateRectangleArea_Request::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::CalculateRectangleArea_Request msg_;
};

class Init_CalculateRectangleArea_Request_height
{
public:
  Init_CalculateRectangleArea_Request_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalculateRectangleArea_Request_width height(::my_robot_interfaces::srv::CalculateRectangleArea_Request::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_CalculateRectangleArea_Request_width(msg_);
  }

private:
  ::my_robot_interfaces::srv::CalculateRectangleArea_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::CalculateRectangleArea_Request>()
{
  return my_robot_interfaces::srv::builder::Init_CalculateRectangleArea_Request_height();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_CalculateRectangleArea_Response_area
{
public:
  Init_CalculateRectangleArea_Response_area()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::srv::CalculateRectangleArea_Response area(::my_robot_interfaces::srv::CalculateRectangleArea_Response::_area_type arg)
  {
    msg_.area = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::CalculateRectangleArea_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::CalculateRectangleArea_Response>()
{
  return my_robot_interfaces::srv::builder::Init_CalculateRectangleArea_Response_area();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_CalculateRectangleArea_Event_response
{
public:
  explicit Init_CalculateRectangleArea_Event_response(::my_robot_interfaces::srv::CalculateRectangleArea_Event & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::CalculateRectangleArea_Event response(::my_robot_interfaces::srv::CalculateRectangleArea_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::CalculateRectangleArea_Event msg_;
};

class Init_CalculateRectangleArea_Event_request
{
public:
  explicit Init_CalculateRectangleArea_Event_request(::my_robot_interfaces::srv::CalculateRectangleArea_Event & msg)
  : msg_(msg)
  {}
  Init_CalculateRectangleArea_Event_response request(::my_robot_interfaces::srv::CalculateRectangleArea_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_CalculateRectangleArea_Event_response(msg_);
  }

private:
  ::my_robot_interfaces::srv::CalculateRectangleArea_Event msg_;
};

class Init_CalculateRectangleArea_Event_info
{
public:
  Init_CalculateRectangleArea_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalculateRectangleArea_Event_request info(::my_robot_interfaces::srv::CalculateRectangleArea_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_CalculateRectangleArea_Event_request(msg_);
  }

private:
  ::my_robot_interfaces::srv::CalculateRectangleArea_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::CalculateRectangleArea_Event>()
{
  return my_robot_interfaces::srv::builder::Init_CalculateRectangleArea_Event_info();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__BUILDER_HPP_
