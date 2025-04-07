// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__BUILDER_HPP_
#define COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "common_interface/msg/detail/key_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace common_interface
{

namespace msg
{

namespace builder
{

class Init_KeyCtrl_manual_spd
{
public:
  explicit Init_KeyCtrl_manual_spd(::common_interface::msg::KeyCtrl & msg)
  : msg_(msg)
  {}
  ::common_interface::msg::KeyCtrl manual_spd(::common_interface::msg::KeyCtrl::_manual_spd_type arg)
  {
    msg_.manual_spd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::common_interface::msg::KeyCtrl msg_;
};

class Init_KeyCtrl_allow_nav
{
public:
  Init_KeyCtrl_allow_nav()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KeyCtrl_manual_spd allow_nav(::common_interface::msg::KeyCtrl::_allow_nav_type arg)
  {
    msg_.allow_nav = std::move(arg);
    return Init_KeyCtrl_manual_spd(msg_);
  }

private:
  ::common_interface::msg::KeyCtrl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::common_interface::msg::KeyCtrl>()
{
  return common_interface::msg::builder::Init_KeyCtrl_allow_nav();
}

}  // namespace common_interface

#endif  // COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__BUILDER_HPP_
