// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__FUNCTIONS_H_
#define COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "common_interface/msg/rosidl_generator_c__visibility_control.h"

#include "common_interface/msg/detail/ser_com_struct__struct.h"

/// Initialize msg/SerComStruct message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * common_interface__msg__SerComStruct
 * )) before or use
 * common_interface__msg__SerComStruct__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
bool
common_interface__msg__SerComStruct__init(common_interface__msg__SerComStruct * msg);

/// Finalize msg/SerComStruct message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
void
common_interface__msg__SerComStruct__fini(common_interface__msg__SerComStruct * msg);

/// Create msg/SerComStruct message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * common_interface__msg__SerComStruct__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
common_interface__msg__SerComStruct *
common_interface__msg__SerComStruct__create();

/// Destroy msg/SerComStruct message.
/**
 * It calls
 * common_interface__msg__SerComStruct__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
void
common_interface__msg__SerComStruct__destroy(common_interface__msg__SerComStruct * msg);

/// Check for msg/SerComStruct message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
bool
common_interface__msg__SerComStruct__are_equal(const common_interface__msg__SerComStruct * lhs, const common_interface__msg__SerComStruct * rhs);

/// Copy a msg/SerComStruct message.
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
ROSIDL_GENERATOR_C_PUBLIC_common_interface
bool
common_interface__msg__SerComStruct__copy(
  const common_interface__msg__SerComStruct * input,
  common_interface__msg__SerComStruct * output);

/// Initialize array of msg/SerComStruct messages.
/**
 * It allocates the memory for the number of elements and calls
 * common_interface__msg__SerComStruct__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
bool
common_interface__msg__SerComStruct__Sequence__init(common_interface__msg__SerComStruct__Sequence * array, size_t size);

/// Finalize array of msg/SerComStruct messages.
/**
 * It calls
 * common_interface__msg__SerComStruct__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
void
common_interface__msg__SerComStruct__Sequence__fini(common_interface__msg__SerComStruct__Sequence * array);

/// Create array of msg/SerComStruct messages.
/**
 * It allocates the memory for the array and calls
 * common_interface__msg__SerComStruct__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
common_interface__msg__SerComStruct__Sequence *
common_interface__msg__SerComStruct__Sequence__create(size_t size);

/// Destroy array of msg/SerComStruct messages.
/**
 * It calls
 * common_interface__msg__SerComStruct__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
void
common_interface__msg__SerComStruct__Sequence__destroy(common_interface__msg__SerComStruct__Sequence * array);

/// Check for msg/SerComStruct message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_common_interface
bool
common_interface__msg__SerComStruct__Sequence__are_equal(const common_interface__msg__SerComStruct__Sequence * lhs, const common_interface__msg__SerComStruct__Sequence * rhs);

/// Copy an array of msg/SerComStruct messages.
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
ROSIDL_GENERATOR_C_PUBLIC_common_interface
bool
common_interface__msg__SerComStruct__Sequence__copy(
  const common_interface__msg__SerComStruct__Sequence * input,
  common_interface__msg__SerComStruct__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__FUNCTIONS_H_
