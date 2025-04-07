// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__STRUCT_H_
#define COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'manual_spd'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/KeyCtrl in the package common_interface.
typedef struct common_interface__msg__KeyCtrl
{
  bool allow_nav;
  geometry_msgs__msg__Twist manual_spd;
} common_interface__msg__KeyCtrl;

// Struct for a sequence of common_interface__msg__KeyCtrl.
typedef struct common_interface__msg__KeyCtrl__Sequence
{
  common_interface__msg__KeyCtrl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} common_interface__msg__KeyCtrl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__STRUCT_H_
