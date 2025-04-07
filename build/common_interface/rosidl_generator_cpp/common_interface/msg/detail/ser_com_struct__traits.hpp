// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__TRAITS_HPP_
#define COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "common_interface/msg/detail/ser_com_struct__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace common_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const SerComStruct & msg,
  std::ostream & out)
{
  out << "{";
  // member: pwm_l
  {
    out << "pwm_l: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_l, out);
    out << ", ";
  }

  // member: pwm_r
  {
    out << "pwm_r: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_r, out);
    out << ", ";
  }

  // member: dir_l
  {
    out << "dir_l: ";
    rosidl_generator_traits::value_to_yaml(msg.dir_l, out);
    out << ", ";
  }

  // member: dir_r
  {
    out << "dir_r: ";
    rosidl_generator_traits::value_to_yaml(msg.dir_r, out);
    out << ", ";
  }

  // member: gear
  {
    out << "gear: ";
    rosidl_generator_traits::value_to_yaml(msg.gear, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SerComStruct & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pwm_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_l: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_l, out);
    out << "\n";
  }

  // member: pwm_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_r: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_r, out);
    out << "\n";
  }

  // member: dir_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dir_l: ";
    rosidl_generator_traits::value_to_yaml(msg.dir_l, out);
    out << "\n";
  }

  // member: dir_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dir_r: ";
    rosidl_generator_traits::value_to_yaml(msg.dir_r, out);
    out << "\n";
  }

  // member: gear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gear: ";
    rosidl_generator_traits::value_to_yaml(msg.gear, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SerComStruct & msg, bool use_flow_style = false)
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
  const common_interface::msg::SerComStruct & msg,
  std::ostream & out, size_t indentation = 0)
{
  common_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use common_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const common_interface::msg::SerComStruct & msg)
{
  return common_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<common_interface::msg::SerComStruct>()
{
  return "common_interface::msg::SerComStruct";
}

template<>
inline const char * name<common_interface::msg::SerComStruct>()
{
  return "common_interface/msg/SerComStruct";
}

template<>
struct has_fixed_size<common_interface::msg::SerComStruct>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<common_interface::msg::SerComStruct>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<common_interface::msg::SerComStruct>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__TRAITS_HPP_
