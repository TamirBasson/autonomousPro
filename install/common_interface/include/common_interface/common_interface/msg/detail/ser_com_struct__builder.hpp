// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__BUILDER_HPP_
#define COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "common_interface/msg/detail/ser_com_struct__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace common_interface
{

namespace msg
{

namespace builder
{

class Init_SerComStruct_gear
{
public:
  explicit Init_SerComStruct_gear(::common_interface::msg::SerComStruct & msg)
  : msg_(msg)
  {}
  ::common_interface::msg::SerComStruct gear(::common_interface::msg::SerComStruct::_gear_type arg)
  {
    msg_.gear = std::move(arg);
    return std::move(msg_);
  }

private:
  ::common_interface::msg::SerComStruct msg_;
};

class Init_SerComStruct_dir_r
{
public:
  explicit Init_SerComStruct_dir_r(::common_interface::msg::SerComStruct & msg)
  : msg_(msg)
  {}
  Init_SerComStruct_gear dir_r(::common_interface::msg::SerComStruct::_dir_r_type arg)
  {
    msg_.dir_r = std::move(arg);
    return Init_SerComStruct_gear(msg_);
  }

private:
  ::common_interface::msg::SerComStruct msg_;
};

class Init_SerComStruct_dir_l
{
public:
  explicit Init_SerComStruct_dir_l(::common_interface::msg::SerComStruct & msg)
  : msg_(msg)
  {}
  Init_SerComStruct_dir_r dir_l(::common_interface::msg::SerComStruct::_dir_l_type arg)
  {
    msg_.dir_l = std::move(arg);
    return Init_SerComStruct_dir_r(msg_);
  }

private:
  ::common_interface::msg::SerComStruct msg_;
};

class Init_SerComStruct_pwm_r
{
public:
  explicit Init_SerComStruct_pwm_r(::common_interface::msg::SerComStruct & msg)
  : msg_(msg)
  {}
  Init_SerComStruct_dir_l pwm_r(::common_interface::msg::SerComStruct::_pwm_r_type arg)
  {
    msg_.pwm_r = std::move(arg);
    return Init_SerComStruct_dir_l(msg_);
  }

private:
  ::common_interface::msg::SerComStruct msg_;
};

class Init_SerComStruct_pwm_l
{
public:
  Init_SerComStruct_pwm_l()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SerComStruct_pwm_r pwm_l(::common_interface::msg::SerComStruct::_pwm_l_type arg)
  {
    msg_.pwm_l = std::move(arg);
    return Init_SerComStruct_pwm_r(msg_);
  }

private:
  ::common_interface::msg::SerComStruct msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::common_interface::msg::SerComStruct>()
{
  return common_interface::msg::builder::Init_SerComStruct_pwm_l();
}

}  // namespace common_interface

#endif  // COMMON_INTERFACE__MSG__DETAIL__SER_COM_STRUCT__BUILDER_HPP_
