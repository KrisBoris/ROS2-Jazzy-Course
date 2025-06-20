// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_robot_interfaces:msg/LedPanelState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_robot_interfaces/msg/detail/led_panel_state__functions.h"
#include "my_robot_interfaces/msg/detail/led_panel_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_robot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LedPanelState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_robot_interfaces::msg::LedPanelState(_init);
}

void LedPanelState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_robot_interfaces::msg::LedPanelState *>(message_memory);
  typed_message->~LedPanelState();
}

size_t size_function__LedPanelState__led_status(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__LedPanelState__led_status(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__LedPanelState__led_status(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__LedPanelState__led_status(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__LedPanelState__led_status(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__LedPanelState__led_status(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__LedPanelState__led_status(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LedPanelState_message_member_array[1] = {
  {
    "led_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces::msg::LedPanelState, led_status),  // bytes offset in struct
    nullptr,  // default value
    size_function__LedPanelState__led_status,  // size() function pointer
    get_const_function__LedPanelState__led_status,  // get_const(index) function pointer
    get_function__LedPanelState__led_status,  // get(index) function pointer
    fetch_function__LedPanelState__led_status,  // fetch(index, &value) function pointer
    assign_function__LedPanelState__led_status,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LedPanelState_message_members = {
  "my_robot_interfaces::msg",  // message namespace
  "LedPanelState",  // message name
  1,  // number of fields
  sizeof(my_robot_interfaces::msg::LedPanelState),
  false,  // has_any_key_member_
  LedPanelState_message_member_array,  // message members
  LedPanelState_init_function,  // function to initialize message memory (memory has to be allocated)
  LedPanelState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LedPanelState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LedPanelState_message_members,
  get_message_typesupport_handle_function,
  &my_robot_interfaces__msg__LedPanelState__get_type_hash,
  &my_robot_interfaces__msg__LedPanelState__get_type_description,
  &my_robot_interfaces__msg__LedPanelState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_robot_interfaces::msg::LedPanelState>()
{
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::LedPanelState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_robot_interfaces, msg, LedPanelState)() {
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::LedPanelState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
