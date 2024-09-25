// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice

#include "ctrl_interface/msg/detail/ctrl_interface__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ctrl_interface
const rosidl_type_hash_t *
ctrl_interface__msg__CtrlInterface__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x06, 0xbb, 0x27, 0xe4, 0x40, 0xb5, 0x3a, 0x37,
      0x4a, 0xc2, 0xb7, 0x0f, 0xf5, 0x3a, 0xb6, 0x31,
      0x50, 0x6e, 0x6c, 0x47, 0x04, 0x28, 0x37, 0x62,
      0x5f, 0xbe, 0x20, 0x39, 0x83, 0x54, 0xc7, 0xbf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ctrl_interface__msg__CtrlInterface__TYPE_NAME[] = "ctrl_interface/msg/CtrlInterface";

// Define type names, field names, and default values
static char ctrl_interface__msg__CtrlInterface__FIELD_NAME__r_motor[] = "r_motor";
static char ctrl_interface__msg__CtrlInterface__FIELD_NAME__l_motor[] = "l_motor";
static char ctrl_interface__msg__CtrlInterface__FIELD_NAME__g_stepper[] = "g_stepper";
static char ctrl_interface__msg__CtrlInterface__FIELD_NAME__s_stepper[] = "s_stepper";

static rosidl_runtime_c__type_description__Field ctrl_interface__msg__CtrlInterface__FIELDS[] = {
  {
    {ctrl_interface__msg__CtrlInterface__FIELD_NAME__r_motor, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ctrl_interface__msg__CtrlInterface__FIELD_NAME__l_motor, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ctrl_interface__msg__CtrlInterface__FIELD_NAME__g_stepper, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ctrl_interface__msg__CtrlInterface__FIELD_NAME__s_stepper, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ctrl_interface__msg__CtrlInterface__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ctrl_interface__msg__CtrlInterface__TYPE_NAME, 32, 32},
      {ctrl_interface__msg__CtrlInterface__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 r_motor\n"
  "int64 l_motor\n"
  "int64 g_stepper\n"
  "int64 s_stepper\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ctrl_interface__msg__CtrlInterface__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ctrl_interface__msg__CtrlInterface__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 61, 61},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ctrl_interface__msg__CtrlInterface__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ctrl_interface__msg__CtrlInterface__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
