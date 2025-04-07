// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "common_interface/msg/detail/key_ctrl__rosidl_typesupport_introspection_c.h"
#include "common_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "common_interface/msg/detail/key_ctrl__functions.h"
#include "common_interface/msg/detail/key_ctrl__struct.h"


// Include directives for member types
// Member `manual_spd`
#include "geometry_msgs/msg/twist.h"
// Member `manual_spd`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  common_interface__msg__KeyCtrl__init(message_memory);
}

void common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_fini_function(void * message_memory)
{
  common_interface__msg__KeyCtrl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_member_array[2] = {
  {
    "allow_nav",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(common_interface__msg__KeyCtrl, allow_nav),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "manual_spd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(common_interface__msg__KeyCtrl, manual_spd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_members = {
  "common_interface__msg",  // message namespace
  "KeyCtrl",  // message name
  2,  // number of fields
  sizeof(common_interface__msg__KeyCtrl),
  common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_member_array,  // message members
  common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_type_support_handle = {
  0,
  &common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_common_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, common_interface, msg, KeyCtrl)() {
  common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  if (!common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_type_support_handle.typesupport_identifier) {
    common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &common_interface__msg__KeyCtrl__rosidl_typesupport_introspection_c__KeyCtrl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
