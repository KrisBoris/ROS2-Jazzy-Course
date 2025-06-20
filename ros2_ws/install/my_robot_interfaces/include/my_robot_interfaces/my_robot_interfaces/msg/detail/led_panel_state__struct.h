// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/LedPanelState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/led_panel_state.h"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_PANEL_STATE__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_PANEL_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/LedPanelState in the package my_robot_interfaces.
/**
  * array representing led panel status
  * array position corresponds to led number 
  * 0 = off, 1 = on
 */
typedef struct my_robot_interfaces__msg__LedPanelState
{
  bool led_status[3];
} my_robot_interfaces__msg__LedPanelState;

// Struct for a sequence of my_robot_interfaces__msg__LedPanelState.
typedef struct my_robot_interfaces__msg__LedPanelState__Sequence
{
  my_robot_interfaces__msg__LedPanelState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__LedPanelState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_PANEL_STATE__STRUCT_H_
