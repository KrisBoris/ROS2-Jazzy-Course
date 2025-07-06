// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_project_interfaces/msg/spawned_turtle.hpp"


#ifndef TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__BUILDER_HPP_
#define TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_project_interfaces
{

namespace msg
{

namespace builder
{

class Init_SpawnedTurtle_pose
{
public:
  explicit Init_SpawnedTurtle_pose(::turtlesim_project_interfaces::msg::SpawnedTurtle & msg)
  : msg_(msg)
  {}
  ::turtlesim_project_interfaces::msg::SpawnedTurtle pose(::turtlesim_project_interfaces::msg::SpawnedTurtle::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_project_interfaces::msg::SpawnedTurtle msg_;
};

class Init_SpawnedTurtle_name
{
public:
  Init_SpawnedTurtle_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpawnedTurtle_pose name(::turtlesim_project_interfaces::msg::SpawnedTurtle::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SpawnedTurtle_pose(msg_);
  }

private:
  ::turtlesim_project_interfaces::msg::SpawnedTurtle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_project_interfaces::msg::SpawnedTurtle>()
{
  return turtlesim_project_interfaces::msg::builder::Init_SpawnedTurtle_name();
}

}  // namespace turtlesim_project_interfaces

#endif  // TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__BUILDER_HPP_
