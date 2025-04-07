// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice
#include "common_interface/msg/detail/ser_com_struct__rosidl_typesupport_fastrtps_cpp.hpp"
#include "common_interface/msg/detail/ser_com_struct__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pwm_l
  cdr << ros_message.pwm_l;
  // Member: pwm_r
  cdr << ros_message.pwm_r;
  // Member: dir_l
  cdr << (ros_message.dir_l ? true : false);
  // Member: dir_r
  cdr << (ros_message.dir_r ? true : false);
  // Member: gear
  cdr << (ros_message.gear ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  common_interface::msg::SerComStruct & ros_message)
{
  // Member: pwm_l
  cdr >> ros_message.pwm_l;

  // Member: pwm_r
  cdr >> ros_message.pwm_r;

  // Member: dir_l
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.dir_l = tmp ? true : false;
  }

  // Member: dir_r
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.dir_r = tmp ? true : false;
  }

  // Member: gear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gear = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
get_serialized_size(
  const common_interface::msg::SerComStruct & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pwm_l
  {
    size_t item_size = sizeof(ros_message.pwm_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pwm_r
  {
    size_t item_size = sizeof(ros_message.pwm_r);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dir_l
  {
    size_t item_size = sizeof(ros_message.dir_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dir_r
  {
    size_t item_size = sizeof(ros_message.dir_r);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gear
  {
    size_t item_size = sizeof(ros_message.gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_common_interface
max_serialized_size_SerComStruct(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: pwm_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pwm_r
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: dir_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: dir_r
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = common_interface::msg::SerComStruct;
    is_plain =
      (
      offsetof(DataType, gear) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SerComStruct__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const common_interface::msg::SerComStruct *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SerComStruct__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<common_interface::msg::SerComStruct *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SerComStruct__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const common_interface::msg::SerComStruct *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SerComStruct__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SerComStruct(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SerComStruct__callbacks = {
  "common_interface::msg",
  "SerComStruct",
  _SerComStruct__cdr_serialize,
  _SerComStruct__cdr_deserialize,
  _SerComStruct__get_serialized_size,
  _SerComStruct__max_serialized_size
};

static rosidl_message_type_support_t _SerComStruct__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SerComStruct__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace common_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_common_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<common_interface::msg::SerComStruct>()
{
  return &common_interface::msg::typesupport_fastrtps_cpp::_SerComStruct__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, common_interface, msg, SerComStruct)() {
  return &common_interface::msg::typesupport_fastrtps_cpp::_SerComStruct__handle;
}

#ifdef __cplusplus
}
#endif
