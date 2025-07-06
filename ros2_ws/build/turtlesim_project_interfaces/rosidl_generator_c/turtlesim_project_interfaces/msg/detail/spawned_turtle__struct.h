// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_project_interfaces/msg/spawned_turtle.h"


#ifndef TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__STRUCT_H_
#define TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "turtlesim/msg/detail/pose__struct.h"

/// Struct defined in msg/SpawnedTurtle in the package turtlesim_project_interfaces.
typedef struct turtlesim_project_interfaces__msg__SpawnedTurtle
{
  rosidl_runtime_c__String name;
  turtlesim__msg__Pose pose;
} turtlesim_project_interfaces__msg__SpawnedTurtle;

// Struct for a sequence of turtlesim_project_interfaces__msg__SpawnedTurtle.
typedef struct turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence
{
  turtlesim_project_interfaces__msg__SpawnedTurtle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__STRUCT_H_
