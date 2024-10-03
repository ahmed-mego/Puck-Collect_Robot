// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ctrl_interface/msg/ctrl_interface.hpp"


#ifndef CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__TRAITS_HPP_
#define CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ctrl_interface/msg/detail/ctrl_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ctrl_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const CtrlInterface & msg,
  std::ostream & out)
{
  out << "{";
  // member: r_motor
  {
    out << "r_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.r_motor, out);
    out << ", ";
  }

  // member: l_motor
  {
    out << "l_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.l_motor, out);
    out << ", ";
  }

  // member: g_stepper
  {
    out << "g_stepper: ";
    rosidl_generator_traits::value_to_yaml(msg.g_stepper, out);
    out << ", ";
  }

  // member: s_stepper
  {
    out << "s_stepper: ";
    rosidl_generator_traits::value_to_yaml(msg.s_stepper, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CtrlInterface & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: r_motor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.r_motor, out);
    out << "\n";
  }

  // member: l_motor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.l_motor, out);
    out << "\n";
  }

  // member: g_stepper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g_stepper: ";
    rosidl_generator_traits::value_to_yaml(msg.g_stepper, out);
    out << "\n";
  }

  // member: s_stepper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_stepper: ";
    rosidl_generator_traits::value_to_yaml(msg.s_stepper, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CtrlInterface & msg, bool use_flow_style = false)
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

}  // namespace ctrl_interface

namespace rosidl_generator_traits
{

[[deprecated("use ctrl_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ctrl_interface::msg::CtrlInterface & msg,
  std::ostream & out, size_t indentation = 0)
{
  ctrl_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ctrl_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const ctrl_interface::msg::CtrlInterface & msg)
{
  return ctrl_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ctrl_interface::msg::CtrlInterface>()
{
  return "ctrl_interface::msg::CtrlInterface";
}

template<>
inline const char * name<ctrl_interface::msg::CtrlInterface>()
{
  return "ctrl_interface/msg/CtrlInterface";
}

template<>
struct has_fixed_size<ctrl_interface::msg::CtrlInterface>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ctrl_interface::msg::CtrlInterface>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ctrl_interface::msg::CtrlInterface>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__TRAITS_HPP_
