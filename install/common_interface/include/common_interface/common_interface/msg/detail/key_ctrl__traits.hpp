// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__TRAITS_HPP_
#define COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "common_interface/msg/detail/key_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'manual_spd'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace common_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyCtrl & msg,
  std::ostream & out)
{
  out << "{";
  // member: allow_nav
  {
    out << "allow_nav: ";
    rosidl_generator_traits::value_to_yaml(msg.allow_nav, out);
    out << ", ";
  }

  // member: manual_spd
  {
    out << "manual_spd: ";
    to_flow_style_yaml(msg.manual_spd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KeyCtrl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: allow_nav
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "allow_nav: ";
    rosidl_generator_traits::value_to_yaml(msg.allow_nav, out);
    out << "\n";
  }

  // member: manual_spd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manual_spd:\n";
    to_block_style_yaml(msg.manual_spd, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyCtrl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace common_interface

namespace rosidl_generator_traits
{

[[deprecated("use common_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const common_interface::msg::KeyCtrl & msg,
  std::ostream & out, size_t indentation = 0)
{
  common_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use common_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const common_interface::msg::KeyCtrl & msg)
{
  return common_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<common_interface::msg::KeyCtrl>()
{
  return "common_interface::msg::KeyCtrl";
}

template<>
inline const char * name<common_interface::msg::KeyCtrl>()
{
  return "common_interface/msg/KeyCtrl";
}

template<>
struct has_fixed_size<common_interface::msg::KeyCtrl>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct has_bounded_size<common_interface::msg::KeyCtrl>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct is_message<common_interface::msg::KeyCtrl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__TRAITS_HPP_
