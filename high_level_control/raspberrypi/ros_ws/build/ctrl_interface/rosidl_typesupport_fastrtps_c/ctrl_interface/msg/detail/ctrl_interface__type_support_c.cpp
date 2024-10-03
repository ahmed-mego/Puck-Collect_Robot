// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice
#include "ctrl_interface/msg/detail/ctrl_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ctrl_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ctrl_interface/msg/detail/ctrl_interface__struct.h"
#include "ctrl_interface/msg/detail/ctrl_interface__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _CtrlInterface__ros_msg_type = ctrl_interface__msg__CtrlInterface;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
bool cdr_serialize_ctrl_interface__msg__CtrlInterface(
  const ctrl_interface__msg__CtrlInterface * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: r_motor
  {
    cdr << ros_message->r_motor;
  }

  // Field name: l_motor
  {
    cdr << ros_message->l_motor;
  }

  // Field name: g_stepper
  {
    cdr << ros_message->g_stepper;
  }

  // Field name: s_stepper
  {
    cdr << ros_message->s_stepper;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
bool cdr_deserialize_ctrl_interface__msg__CtrlInterface(
  eprosima::fastcdr::Cdr & cdr,
  ctrl_interface__msg__CtrlInterface * ros_message)
{
  // Field name: r_motor
  {
    cdr >> ros_message->r_motor;
  }

  // Field name: l_motor
  {
    cdr >> ros_message->l_motor;
  }

  // Field name: g_stepper
  {
    cdr >> ros_message->g_stepper;
  }

  // Field name: s_stepper
  {
    cdr >> ros_message->s_stepper;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t get_serialized_size_ctrl_interface__msg__CtrlInterface(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CtrlInterface__ros_msg_type * ros_message = static_cast<const _CtrlInterface__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: r_motor
  {
    size_t item_size = sizeof(ros_message->r_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: l_motor
  {
    size_t item_size = sizeof(ros_message->l_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: g_stepper
  {
    size_t item_size = sizeof(ros_message->g_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: s_stepper
  {
    size_t item_size = sizeof(ros_message->s_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t max_serialized_size_ctrl_interface__msg__CtrlInterface(
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

  // Field name: r_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: l_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: g_stepper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: s_stepper
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
    using DataType = ctrl_interface__msg__CtrlInterface;
    is_plain =
      (
      offsetof(DataType, s_stepper) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
bool cdr_serialize_key_ctrl_interface__msg__CtrlInterface(
  const ctrl_interface__msg__CtrlInterface * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: r_motor
  {
    cdr << ros_message->r_motor;
  }

  // Field name: l_motor
  {
    cdr << ros_message->l_motor;
  }

  // Field name: g_stepper
  {
    cdr << ros_message->g_stepper;
  }

  // Field name: s_stepper
  {
    cdr << ros_message->s_stepper;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t get_serialized_size_key_ctrl_interface__msg__CtrlInterface(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CtrlInterface__ros_msg_type * ros_message = static_cast<const _CtrlInterface__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: r_motor
  {
    size_t item_size = sizeof(ros_message->r_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: l_motor
  {
    size_t item_size = sizeof(ros_message->l_motor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: g_stepper
  {
    size_t item_size = sizeof(ros_message->g_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: s_stepper
  {
    size_t item_size = sizeof(ros_message->s_stepper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ctrl_interface
size_t max_serialized_size_key_ctrl_interface__msg__CtrlInterface(
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
  // Field name: r_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: l_motor
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: g_stepper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: s_stepper
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
    using DataType = ctrl_interface__msg__CtrlInterface;
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
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ctrl_interface__msg__CtrlInterface * ros_message = static_cast<const ctrl_interface__msg__CtrlInterface *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ctrl_interface__msg__CtrlInterface(ros_message, cdr);
}

static bool _CtrlInterface__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ctrl_interface__msg__CtrlInterface * ros_message = static_cast<ctrl_interface__msg__CtrlInterface *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ctrl_interface__msg__CtrlInterface(cdr, ros_message);
}

static uint32_t _CtrlInterface__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ctrl_interface__msg__CtrlInterface(
      untyped_ros_message, 0));
}

static size_t _CtrlInterface__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ctrl_interface__msg__CtrlInterface(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CtrlInterface = {
  "ctrl_interface::msg",
  "CtrlInterface",
  _CtrlInterface__cdr_serialize,
  _CtrlInterface__cdr_deserialize,
  _CtrlInterface__get_serialized_size,
  _CtrlInterface__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CtrlInterface__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CtrlInterface,
  get_message_typesupport_handle_function,
  &ctrl_interface__msg__CtrlInterface__get_type_hash,
  &ctrl_interface__msg__CtrlInterface__get_type_description,
  &ctrl_interface__msg__CtrlInterface__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ctrl_interface, msg, CtrlInterface)() {
  return &_CtrlInterface__type_support;
}

#if defined(__cplusplus)
}
#endif
