// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "common_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "common_interface/msg/detail/ser_com_struct__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace common_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
cdr_serialize(
  const common_interface::msg::SerComStruct & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  common_interface::msg::SerComStruct & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
get_serialized_size(
  const common_interface::msg::SerComStruct & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
max_serialized_size_SerComStruct(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace common_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, common_interface, msg, SerComStruct)();

#ifdef __cplusplus
}
#endif

#endif  // COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
