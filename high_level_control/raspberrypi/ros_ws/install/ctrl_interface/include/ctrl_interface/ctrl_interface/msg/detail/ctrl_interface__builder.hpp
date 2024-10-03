// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ctrl_interface/msg/ctrl_interface.hpp"


#ifndef CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__BUILDER_HPP_
#define CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ctrl_interface/msg/detail/ctrl_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ctrl_interface
{

namespace msg
{

namespace builder
{

class Init_CtrlInterface_s_stepper
{
public:
  explicit Init_CtrlInterface_s_stepper(::ctrl_interface::msg::CtrlInterface & msg)
  : msg_(msg)
  {}
  ::ctrl_interface::msg::CtrlInterface s_stepper(::ctrl_interface::msg::CtrlInterface::_s_stepper_type arg)
  {
    msg_.s_stepper = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ctrl_interface::msg::CtrlInterface msg_;
};

class Init_CtrlInterface_g_stepper
{
public:
  explicit Init_CtrlInterface_g_stepper(::ctrl_interface::msg::CtrlInterface & msg)
  : msg_(msg)
  {}
  Init_CtrlInterface_s_stepper g_stepper(::ctrl_interface::msg::CtrlInterface::_g_stepper_type arg)
  {
    msg_.g_stepper = std::move(arg);
    return Init_CtrlInterface_s_stepper(msg_);
  }

private:
  ::ctrl_interface::msg::CtrlInterface msg_;
};

class Init_CtrlInterface_l_motor
{
public:
  explicit Init_CtrlInterface_l_motor(::ctrl_interface::msg::CtrlInterface & msg)
  : msg_(msg)
  {}
  Init_CtrlInterface_g_stepper l_motor(::ctrl_interface::msg::CtrlInterface::_l_motor_type arg)
  {
    msg_.l_motor = std::move(arg);
    return Init_CtrlInterface_g_stepper(msg_);
  }

private:
  ::ctrl_interface::msg::CtrlInterface msg_;
};

class Init_CtrlInterface_r_motor
{
public:
  Init_CtrlInterface_r_motor()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CtrlInterface_l_motor r_motor(::ctrl_interface::msg::CtrlInterface::_r_motor_type arg)
  {
    msg_.r_motor = std::move(arg);
    return Init_CtrlInterface_l_motor(msg_);
  }

private:
  ::ctrl_interface::msg::CtrlInterface msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ctrl_interface::msg::CtrlInterface>()
{
  return ctrl_interface::msg::builder::Init_CtrlInterface_r_motor();
}

}  // namespace ctrl_interface

#endif  // CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__BUILDER_HPP_
