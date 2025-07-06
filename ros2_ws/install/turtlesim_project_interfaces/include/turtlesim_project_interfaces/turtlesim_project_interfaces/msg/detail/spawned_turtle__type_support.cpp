// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__functions.h"
#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace turtlesim_project_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SpawnedTurtle_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) turtlesim_project_interfaces::msg::SpawnedTurtle(_init);
}

void SpawnedTurtle_fini_function(void * message_memory)
{
  auto typed_message = static_cast<turtlesim_project_interfaces::msg::SpawnedTurtle *>(message_memory);
  typed_message->~SpawnedTurtle();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SpawnedTurtle_message_member_array[2] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_project_interfaces::msg::SpawnedTurtle, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<turtlesim::msg::Pose>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_project_interfaces::msg::SpawnedTurtle, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SpawnedTurtle_message_members = {
  "turtlesim_project_interfaces::msg",  // message namespace
  "SpawnedTurtle",  // message name
  2,  // number of fields
  sizeof(turtlesim_project_interfaces::msg::SpawnedTurtle),
  false,  // has_any_key_member_
  SpawnedTurtle_message_member_array,  // message members
  SpawnedTurtle_init_function,  // function to initialize message memory (memory has to be allocated)
  SpawnedTurtle_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SpawnedTurtle_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SpawnedTurtle_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_hash,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace turtlesim_project_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtlesim_project_interfaces::msg::SpawnedTurtle>()
{
  return &::turtlesim_project_interfaces::msg::rosidl_typesupport_introspection_cpp::SpawnedTurtle_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtlesim_project_interfaces, msg, SpawnedTurtle)() {
  return &::turtlesim_project_interfaces::msg::rosidl_typesupport_introspection_cpp::SpawnedTurtle_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
