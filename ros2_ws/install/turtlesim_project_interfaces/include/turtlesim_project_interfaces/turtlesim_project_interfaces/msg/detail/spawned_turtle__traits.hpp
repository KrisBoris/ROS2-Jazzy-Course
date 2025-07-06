// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_project_interfaces/msg/spawned_turtle.hpp"


#ifndef TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__TRAITS_HPP_
#define TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "turtlesim/msg/detail/pose__traits.hpp"

namespace turtlesim_project_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpawnedTurtle & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpawnedTurtle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpawnedTurtle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtlesim_project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtlesim_project_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlesim_project_interfaces::msg::SpawnedTurtle & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlesim_project_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlesim_project_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtlesim_project_interfaces::msg::SpawnedTurtle & msg)
{
  return turtlesim_project_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtlesim_project_interfaces::msg::SpawnedTurtle>()
{
  return "turtlesim_project_interfaces::msg::SpawnedTurtle";
}

template<>
inline const char * name<turtlesim_project_interfaces::msg::SpawnedTurtle>()
{
  return "turtlesim_project_interfaces/msg/SpawnedTurtle";
}

template<>
struct has_fixed_size<turtlesim_project_interfaces::msg::SpawnedTurtle>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_project_interfaces::msg::SpawnedTurtle>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turtlesim_project_interfaces::msg::SpawnedTurtle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__TRAITS_HPP_
