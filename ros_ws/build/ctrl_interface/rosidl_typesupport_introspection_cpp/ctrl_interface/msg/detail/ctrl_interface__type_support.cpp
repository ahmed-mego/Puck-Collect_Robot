// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ctrl_interface/msg/detail/ctrl_interface__functions.h"
#include "ctrl_interface/msg/detail/ctrl_interface__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ctrl_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CtrlInterface_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ctrl_interface::msg::CtrlInterface(_init);
}

void CtrlInterface_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ctrl_interface::msg::CtrlInterface *>(message_memory);
  typed_message->~CtrlInterface();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CtrlInterface_message_member_array[4] = {
  {
    "r_motor",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ctrl_interface::msg::CtrlInterface, r_motor),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "l_motor",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ctrl_interface::msg::CtrlInterface, l_motor),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "g_stepper",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ctrl_interface::msg::CtrlInterface, g_stepper),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "s_stepper",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ctrl_interface::msg::CtrlInterface, s_stepper),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CtrlInterface_message_members = {
  "ctrl_interface::msg",  // message namespace
  "CtrlInterface",  // message name
  4,  // number of fields
  sizeof(ctrl_interface::msg::CtrlInterface),
  false,  // has_any_key_member_
  CtrlInterface_message_member_array,  // message members
  CtrlInterface_init_function,  // function to initialize message memory (memory has to be allocated)
  CtrlInterface_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CtrlInterface_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CtrlInterface_message_members,
  get_message_typesupport_handle_function,
  &ctrl_interface__msg__CtrlInterface__get_type_hash,
  &ctrl_interface__msg__CtrlInterface__get_type_description,
  &ctrl_interface__msg__CtrlInterface__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ctrl_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ctrl_interface::msg::CtrlInterface>()
{
  return &::ctrl_interface::msg::rosidl_typesupport_introspection_cpp::CtrlInterface_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ctrl_interface, msg, CtrlInterface)() {
  return &::ctrl_interface::msg::rosidl_typesupport_introspection_cpp::CtrlInterface_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
