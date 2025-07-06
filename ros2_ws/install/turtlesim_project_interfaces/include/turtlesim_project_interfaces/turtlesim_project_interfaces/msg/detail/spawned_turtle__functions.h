// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_project_interfaces/msg/spawned_turtle.h"


#ifndef TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__FUNCTIONS_H_
#define TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "turtlesim_project_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__struct.h"

/// Initialize msg/SpawnedTurtle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turtlesim_project_interfaces__msg__SpawnedTurtle
 * )) before or use
 * turtlesim_project_interfaces__msg__SpawnedTurtle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
bool
turtlesim_project_interfaces__msg__SpawnedTurtle__init(turtlesim_project_interfaces__msg__SpawnedTurtle * msg);

/// Finalize msg/SpawnedTurtle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
void
turtlesim_project_interfaces__msg__SpawnedTurtle__fini(turtlesim_project_interfaces__msg__SpawnedTurtle * msg);

/// Create msg/SpawnedTurtle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turtlesim_project_interfaces__msg__SpawnedTurtle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
turtlesim_project_interfaces__msg__SpawnedTurtle *
turtlesim_project_interfaces__msg__SpawnedTurtle__create(void);

/// Destroy msg/SpawnedTurtle message.
/**
 * It calls
 * turtlesim_project_interfaces__msg__SpawnedTurtle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
void
turtlesim_project_interfaces__msg__SpawnedTurtle__destroy(turtlesim_project_interfaces__msg__SpawnedTurtle * msg);

/// Check for msg/SpawnedTurtle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
bool
turtlesim_project_interfaces__msg__SpawnedTurtle__are_equal(const turtlesim_project_interfaces__msg__SpawnedTurtle * lhs, const turtlesim_project_interfaces__msg__SpawnedTurtle * rhs);

/// Copy a msg/SpawnedTurtle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
bool
turtlesim_project_interfaces__msg__SpawnedTurtle__copy(
  const turtlesim_project_interfaces__msg__SpawnedTurtle * input,
  turtlesim_project_interfaces__msg__SpawnedTurtle * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
const rosidl_type_hash_t *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
const rosidl_runtime_c__type_description__TypeSource *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/SpawnedTurtle messages.
/**
 * It allocates the memory for the number of elements and calls
 * turtlesim_project_interfaces__msg__SpawnedTurtle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
bool
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__init(turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * array, size_t size);

/// Finalize array of msg/SpawnedTurtle messages.
/**
 * It calls
 * turtlesim_project_interfaces__msg__SpawnedTurtle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
void
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__fini(turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * array);

/// Create array of msg/SpawnedTurtle messages.
/**
 * It allocates the memory for the array and calls
 * turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence *
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__create(size_t size);

/// Destroy array of msg/SpawnedTurtle messages.
/**
 * It calls
 * turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
void
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__destroy(turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * array);

/// Check for msg/SpawnedTurtle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
bool
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__are_equal(const turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * lhs, const turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * rhs);

/// Copy an array of msg/SpawnedTurtle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
bool
turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence__copy(
  const turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * input,
  turtlesim_project_interfaces__msg__SpawnedTurtle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__FUNCTIONS_H_
