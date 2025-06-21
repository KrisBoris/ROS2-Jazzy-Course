// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/CalculateRectangleArea.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/srv/calculate_rectangle_area.h"


#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CalculateRectangleArea in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__CalculateRectangleArea_Request
{
  double height;
  double width;
} my_robot_interfaces__srv__CalculateRectangleArea_Request;

// Struct for a sequence of my_robot_interfaces__srv__CalculateRectangleArea_Request.
typedef struct my_robot_interfaces__srv__CalculateRectangleArea_Request__Sequence
{
  my_robot_interfaces__srv__CalculateRectangleArea_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__CalculateRectangleArea_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/CalculateRectangleArea in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__CalculateRectangleArea_Response
{
  double area;
} my_robot_interfaces__srv__CalculateRectangleArea_Response;

// Struct for a sequence of my_robot_interfaces__srv__CalculateRectangleArea_Response.
typedef struct my_robot_interfaces__srv__CalculateRectangleArea_Response__Sequence
{
  my_robot_interfaces__srv__CalculateRectangleArea_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__CalculateRectangleArea_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  my_robot_interfaces__srv__CalculateRectangleArea_Event__request__MAX_SIZE = 1
};
// response
enum
{
  my_robot_interfaces__srv__CalculateRectangleArea_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/CalculateRectangleArea in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__CalculateRectangleArea_Event
{
  service_msgs__msg__ServiceEventInfo info;
  my_robot_interfaces__srv__CalculateRectangleArea_Request__Sequence request;
  my_robot_interfaces__srv__CalculateRectangleArea_Response__Sequence response;
} my_robot_interfaces__srv__CalculateRectangleArea_Event;

// Struct for a sequence of my_robot_interfaces__srv__CalculateRectangleArea_Event.
typedef struct my_robot_interfaces__srv__CalculateRectangleArea_Event__Sequence
{
  my_robot_interfaces__srv__CalculateRectangleArea_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__CalculateRectangleArea_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__STRUCT_H_
