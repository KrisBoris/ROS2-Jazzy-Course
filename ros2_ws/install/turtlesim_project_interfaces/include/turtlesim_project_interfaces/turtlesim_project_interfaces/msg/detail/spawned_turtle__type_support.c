// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__rosidl_typesupport_introspection_c.h"
#include "turtlesim_project_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__functions.h"
#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "turtlesim/msg/pose.h"
// Member `pose`
#include "turtlesim/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_project_interfaces__msg__SpawnedTurtle__init(message_memory);
}

void turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_fini_function(void * message_memory)
{
  turtlesim_project_interfaces__msg__SpawnedTurtle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_member_array[2] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_project_interfaces__msg__SpawnedTurtle, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_project_interfaces__msg__SpawnedTurtle, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_members = {
  "turtlesim_project_interfaces__msg",  // message namespace
  "SpawnedTurtle",  // message name
  2,  // number of fields
  sizeof(turtlesim_project_interfaces__msg__SpawnedTurtle),
  false,  // has_any_key_member_
  turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_member_array,  // message members
  turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_type_support_handle = {
  0,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_hash,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description,
  &turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_project_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_project_interfaces, msg, SpawnedTurtle)() {
  turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim, msg, Pose)();
  if (!turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_type_support_handle.typesupport_identifier) {
    turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_project_interfaces__msg__SpawnedTurtle__rosidl_typesupport_introspection_c__SpawnedTurtle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
