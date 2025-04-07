// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__STRUCT_H_
#define COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SerComStruct in the package common_interface.
typedef struct common_interface__msg__SerComStruct
{
  int64_t pwm_l;
  int64_t pwm_r;
  bool dir_l;
  bool dir_r;
  bool gear;
} common_interface__msg__SerComStruct;

// Struct for a sequence of common_interface__msg__SerComStruct.
typedef struct common_interface__msg__SerComStruct__Sequence
{
  common_interface__msg__SerComStruct * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} common_interface__msg__SerComStruct__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__STRUCT_H_
