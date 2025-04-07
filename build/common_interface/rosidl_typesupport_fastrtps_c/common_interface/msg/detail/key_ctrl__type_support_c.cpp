// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice
#include "common_interface/msg/detail/key_ctrl__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "common_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "common_interface/msg/detail/key_ctrl__struct.h"
#include "common_interface/msg/detail/key_ctrl__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/twist__functions.h"  // manual_spd

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_common_interface
size_t get_serialized_size_geometry_msgs__msg__Twist(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_common_interface
size_t max_serialized_size_geometry_msgs__msg__Twist(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_common_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Twist)();


using _KeyCtrl__ros_msg_type = common_interface__msg__KeyCtrl;

static bool _KeyCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _KeyCtrl__ros_msg_type * ros_message = static_cast<const _KeyCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: allow_nav
  {
    cdr << (ros_message->allow_nav ? true : false);
  }

  // Field name: manual_spd
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Twist
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->manual_spd, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _KeyCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _KeyCtrl__ros_msg_type * ros_message = static_cast<_KeyCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: allow_nav
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->allow_nav = tmp ? true : false;
  }

  // Field name: manual_spd
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Twist
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->manual_spd))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_common_interface
size_t get_serialized_size_common_interface__msg__KeyCtrl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _KeyCtrl__ros_msg_type * ros_message = static_cast<const _KeyCtrl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name allow_nav
  {
    size_t item_size = sizeof(ros_message->allow_nav);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name manual_spd

  current_alignment += get_serialized_size_geometry_msgs__msg__Twist(
    &(ros_message->manual_spd), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _KeyCtrl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_common_interface__msg__KeyCtrl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_common_interface
size_t max_serialized_size_common_interface__msg__KeyCtrl(
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

  // member: allow_nav
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: manual_spd
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = common_interface__msg__KeyCtrl;
    is_plain =
      (
      offsetof(DataType, manual_spd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _KeyCtrl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_common_interface__msg__KeyCtrl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_KeyCtrl = {
  "common_interface::msg",
  "KeyCtrl",
  _KeyCtrl__cdr_serialize,
  _KeyCtrl__cdr_deserialize,
  _KeyCtrl__get_serialized_size,
  _KeyCtrl__max_serialized_size
};

static rosidl_message_type_support_t _KeyCtrl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_KeyCtrl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, common_interface, msg, KeyCtrl)() {
  return &_KeyCtrl__type_support;
}

#if defined(__cplusplus)
}
#endif
