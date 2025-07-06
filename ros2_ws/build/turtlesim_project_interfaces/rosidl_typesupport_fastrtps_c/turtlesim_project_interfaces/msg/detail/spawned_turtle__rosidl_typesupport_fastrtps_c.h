// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice
#ifndef TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlesim_project_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
bool cdr_serialize_turtlesim_project_interfaces__msg__SpawnedTurtle(
  const turtlesim_project_interfaces__msg__SpawnedTurtle * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
bool cdr_deserialize_turtlesim_project_interfaces__msg__SpawnedTurtle(
  eprosima::fastcdr::Cdr &,
  turtlesim_project_interfaces__msg__SpawnedTurtle * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
size_t get_serialized_size_turtlesim_project_interfaces__msg__SpawnedTurtle(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
size_t max_serialized_size_turtlesim_project_interfaces__msg__SpawnedTurtle(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
bool cdr_serialize_key_turtlesim_project_interfaces__msg__SpawnedTurtle(
  const turtlesim_project_interfaces__msg__SpawnedTurtle * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
size_t get_serialized_size_key_turtlesim_project_interfaces__msg__SpawnedTurtle(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
size_t max_serialized_size_key_turtlesim_project_interfaces__msg__SpawnedTurtle(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_project_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtlesim_project_interfaces, msg, SpawnedTurtle)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
