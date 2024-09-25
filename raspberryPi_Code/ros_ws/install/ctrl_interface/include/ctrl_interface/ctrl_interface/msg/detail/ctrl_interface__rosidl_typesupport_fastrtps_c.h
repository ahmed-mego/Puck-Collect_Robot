// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice
#ifndef CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ctrl_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ctrl_interface/msg/detail/ctrl_interface__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
bool cdr_serialize_ctrl_interface__msg__CtrlInterface(
  const ctrl_interface__msg__CtrlInterface * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
bool cdr_deserialize_ctrl_interface__msg__CtrlInterface(
  eprosima::fastcdr::Cdr &,
  ctrl_interface__msg__CtrlInterface * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t get_serialized_size_ctrl_interface__msg__CtrlInterface(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t max_serialized_size_ctrl_interface__msg__CtrlInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
bool cdr_serialize_key_ctrl_interface__msg__CtrlInterface(
  const ctrl_interface__msg__CtrlInterface * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t get_serialized_size_key_ctrl_interface__msg__CtrlInterface(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t max_serialized_size_key_ctrl_interface__msg__CtrlInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ctrl_interface, msg, CtrlInterface)();

#ifdef __cplusplus
}
#endif

#endif  // CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
