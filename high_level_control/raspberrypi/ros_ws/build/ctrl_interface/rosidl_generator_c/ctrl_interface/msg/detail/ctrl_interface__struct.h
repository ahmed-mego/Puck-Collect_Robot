// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ctrl_interface/msg/ctrl_interface.h"


#ifndef CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__STRUCT_H_
#define CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CtrlInterface in the package ctrl_interface.
typedef struct ctrl_interface__msg__CtrlInterface
{
  int64_t r_motor;
  int64_t l_motor;
  int64_t g_stepper;
  int64_t s_stepper;
} ctrl_interface__msg__CtrlInterface;

// Struct for a sequence of ctrl_interface__msg__CtrlInterface.
typedef struct ctrl_interface__msg__CtrlInterface__Sequence
{
  ctrl_interface__msg__CtrlInterface * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ctrl_interface__msg__CtrlInterface__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CTRL_INTERFACE__MSG__DETAIL__CTRL_INTERFACE__STRUCT_H_
