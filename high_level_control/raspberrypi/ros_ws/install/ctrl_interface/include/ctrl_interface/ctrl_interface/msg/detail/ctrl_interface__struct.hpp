// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ctrl_interface/msg/ctrl_interface.hpp"


#ifndef CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__STRUCT_HPP_
#define CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ctrl_interface__msg__CtrlInterface __attribute__((deprecated))
#else
# define DEPRECATED__ctrl_interface__msg__CtrlInterface __declspec(deprecated)
#endif

namespace ctrl_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CtrlInterface_
{
  using Type = CtrlInterface_<ContainerAllocator>;

  explicit CtrlInterface_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->r_motor = 0ll;
      this->l_motor = 0ll;
      this->g_stepper = 0ll;
      this->s_stepper = 0ll;
    }
  }

  explicit CtrlInterface_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->r_motor = 0ll;
      this->l_motor = 0ll;
      this->g_stepper = 0ll;
      this->s_stepper = 0ll;
    }
  }

  // field types and members
  using _r_motor_type =
    int64_t;
  _r_motor_type r_motor;
  using _l_motor_type =
    int64_t;
  _l_motor_type l_motor;
  using _g_stepper_type =
    int64_t;
  _g_stepper_type g_stepper;
  using _s_stepper_type =
    int64_t;
  _s_stepper_type s_stepper;

  // setters for named parameter idiom
  Type & set__r_motor(
    const int64_t & _arg)
  {
    this->r_motor = _arg;
    return *this;
  }
  Type & set__l_motor(
    const int64_t & _arg)
  {
    this->l_motor = _arg;
    return *this;
  }
  Type & set__g_stepper(
    const int64_t & _arg)
  {
    this->g_stepper = _arg;
    return *this;
  }
  Type & set__s_stepper(
    const int64_t & _arg)
  {
    this->s_stepper = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ctrl_interface::msg::CtrlInterface_<ContainerAllocator> *;
  using ConstRawPtr =
    const ctrl_interface::msg::CtrlInterface_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ctrl_interface::msg::CtrlInterface_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ctrl_interface::msg::CtrlInterface_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ctrl_interface__msg__CtrlInterface
    std::shared_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ctrl_interface__msg__CtrlInterface
    std::shared_ptr<ctrl_interface::msg::CtrlInterface_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CtrlInterface_ & other) const
  {
    if (this->r_motor != other.r_motor) {
      return false;
    }
    if (this->l_motor != other.l_motor) {
      return false;
    }
    if (this->g_stepper != other.g_stepper) {
      return false;
    }
    if (this->s_stepper != other.s_stepper) {
      return false;
    }
    return true;
  }
  bool operator!=(const CtrlInterface_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CtrlInterface_

// alias to use template instance with default allocator
using CtrlInterface =
  ctrl_interface::msg::CtrlInterface_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ctrl_interface

#endif  // CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__STRUCT_HPP_
