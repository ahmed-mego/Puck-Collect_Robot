// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice
#include "ctrl_interface/msg/detail/ctrl_interface__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ctrl_interface/msg/detail/ctrl_interface__functions.h"
#include "ctrl_interface/msg/detail/ctrl_interface__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: r_motor
  cdr << ros_message.r_motor;

  // Member: l_motor
  cdr << ros_message.l_motor;

  // Member: g_stepper
  cdr << ros_message.g_stepper;

  // Member: s_stepper
  cdr << ros_message.s_stepper;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ctrl_interface::msg::CtrlInterface & ros_message)
{
  // Member: r_motor
  cdr >> ros_message.r_motor;

  // Member: l_motor
  cdr >> ros_message.l_motor;

  // Member: g_stepper
  cdr >> ros_message.g_stepper;

  // Member: s_stepper
  cdr >> ros_message.s_stepper;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
get_serialized_size(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: r_motor
  {
    size_t item_size = sizeof(ros_message.r_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: l_motor
  {
    size_t item_size = sizeof(ros_message.l_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: g_stepper
  {
    size_t item_size = sizeof(ros_message.g_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: s_stepper
  {
    size_t item_size = sizeof(ros_message.s_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
max_serialized_size_CtrlInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: r_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: l_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: g_stepper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: s_stepper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ctrl_interface::msg::CtrlInterface;
    is_plain =
      (
      offsetof(DataType, s_stepper) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
cdr_serialize_key(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: r_motor
  cdr << ros_message.r_motor;

  // Member: l_motor
  cdr << ros_message.l_motor;

  // Member: g_stepper
  cdr << ros_message.g_stepper;

  // Member: s_stepper
  cdr << ros_message.s_stepper;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
get_serialized_size_key(
  const ctrl_interface::msg::CtrlInterface & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: r_motor
  {
    size_t item_size = sizeof(ros_message.r_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: l_motor
  {
    size_t item_size = sizeof(ros_message.l_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: g_stepper
  {
    size_t item_size = sizeof(ros_message.g_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: s_stepper
  {
    size_t item_size = sizeof(ros_message.s_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ctrl_interface
max_serialized_size_key_CtrlInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: r_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: l_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: g_stepper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: s_stepper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ctrl_interface::msg::CtrlInterface;
    is_plain =
      (
      offsetof(DataType, s_stepper) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _CtrlInterface__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ctrl_interface::msg::CtrlInterface *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CtrlInterface__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ctrl_interface::msg::CtrlInterface *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CtrlInterface__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ctrl_interface::msg::CtrlInterface *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CtrlInterface__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CtrlInterface(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CtrlInterface__callbacks = {
  "ctrl_interface::msg",
  "CtrlInterface",
  _CtrlInterface__cdr_serialize,
  _CtrlInterface__cdr_deserialize,
  _CtrlInterface__get_serialized_size,
  _CtrlInterface__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CtrlInterface__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CtrlInterface__callbacks,
  get_message_typesupport_handle_function,
  &ctrl_interface__msg__CtrlInterface__get_type_hash,
  &ctrl_interface__msg__CtrlInterface__get_type_description,
  &ctrl_interface__msg__CtrlInterface__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ctrl_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ctrl_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<ctrl_interface::msg::CtrlInterface>()
{
  return &ctrl_interface::msg::typesupport_fastrtps_cpp::_CtrlInterface__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ctrl_interface, msg, CtrlInterface)() {
  return &ctrl_interface::msg::typesupport_fastrtps_cpp::_CtrlInterface__handle;
}

#ifdef __cplusplus
}
#endif
