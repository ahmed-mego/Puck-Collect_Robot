// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

#ifndef CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ctrl_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ctrl_interface/msg/detail/ctrl_interface__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ctrl_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
cdr_serialize(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ctrl_interface::msg::CtrlInterface & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
get_serialized_size(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
max_serialized_size_CtrlInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
cdr_serialize_key(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
get_serialized_size_key(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
max_serialized_size_key_CtrlInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ctrl_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ctrl_interface, msg, CtrlInterface)();

#ifdef __cplusplus
}
#endif

#endif  // CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
