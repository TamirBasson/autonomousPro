// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "common_interface/msg/detail/key_ctrl__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace common_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void KeyCtrl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) common_interface::msg::KeyCtrl(_init);
}

void KeyCtrl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<common_interface::msg::KeyCtrl *>(message_memory);
  typed_message->~KeyCtrl();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember KeyCtrl_message_member_array[2] = {
  {
    "allow_nav",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(common_interface::msg::KeyCtrl, allow_nav),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "manual_spd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Twist>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(common_interface::msg::KeyCtrl, manual_spd),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers KeyCtrl_message_members = {
  "common_interface::msg",  // message namespace
  "KeyCtrl",  // message name
  2,  // number of fields
  sizeof(common_interface::msg::KeyCtrl),
  KeyCtrl_message_member_array,  // message members
  KeyCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  KeyCtrl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t KeyCtrl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &KeyCtrl_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace common_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<common_interface::msg::KeyCtrl>()
{
  return &::common_interface::msg::rosidl_typesupport_introspection_cpp::KeyCtrl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, common_interface, msg, KeyCtrl)() {
  return &::common_interface::msg::rosidl_typesupport_introspection_cpp::KeyCtrl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
