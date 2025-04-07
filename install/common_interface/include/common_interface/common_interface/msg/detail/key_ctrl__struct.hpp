// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice

#ifndef COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__STRUCT_HPP_
#define COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'manual_spd'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__common_interface__msg__KeyCtrl __attribute__((deprecated))
#else
# define DEPRECATED__common_interface__msg__KeyCtrl __declspec(deprecated)
#endif

namespace common_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyCtrl_
{
  using Type = KeyCtrl_<ContainerAllocator>;

  explicit KeyCtrl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : manual_spd(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->allow_nav = false;
    }
  }

  explicit KeyCtrl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : manual_spd(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->allow_nav = false;
    }
  }

  // field types and members
  using _allow_nav_type =
    bool;
  _allow_nav_type allow_nav;
  using _manual_spd_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _manual_spd_type manual_spd;

  // setters for named parameter idiom
  Type & set__allow_nav(
    const bool & _arg)
  {
    this->allow_nav = _arg;
    return *this;
  }
  Type & set__manual_spd(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->manual_spd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    common_interface::msg::KeyCtrl_<ContainerAllocator> *;
  using ConstRawPtr =
    const common_interface::msg::KeyCtrl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      common_interface::msg::KeyCtrl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      common_interface::msg::KeyCtrl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__common_interface__msg__KeyCtrl
    std::shared_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__common_interface__msg__KeyCtrl
    std::shared_ptr<common_interface::msg::KeyCtrl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyCtrl_ & other) const
  {
    if (this->allow_nav != other.allow_nav) {
      return false;
    }
    if (this->manual_spd != other.manual_spd) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyCtrl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyCtrl_

// alias to use template instance with default allocator
using KeyCtrl =
  common_interface::msg::KeyCtrl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace common_interface

#endif  // COMMON_INTERFACE__MSG__DETAIL__KEY_CTRL__STRUCT_HPP_
