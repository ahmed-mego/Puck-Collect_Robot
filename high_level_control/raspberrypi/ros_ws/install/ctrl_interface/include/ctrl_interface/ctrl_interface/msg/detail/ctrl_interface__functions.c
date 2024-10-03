// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice
#include "ctrl_interface/msg/detail/ctrl_interface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ctrl_interface__msg__CtrlInterface__init(ctrl_interface__msg__CtrlInterface * msg)
{
  if (!msg) {
    return false;
  }
  // r_motor
  // l_motor
  // g_stepper
  // s_stepper
  return true;
}

void
ctrl_interface__msg__CtrlInterface__fini(ctrl_interface__msg__CtrlInterface * msg)
{
  if (!msg) {
    return;
  }
  // r_motor
  // l_motor
  // g_stepper
  // s_stepper
}

bool
ctrl_interface__msg__CtrlInterface__are_equal(const ctrl_interface__msg__CtrlInterface * lhs, const ctrl_interface__msg__CtrlInterface * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // r_motor
  if (lhs->r_motor != rhs->r_motor) {
    return false;
  }
  // l_motor
  if (lhs->l_motor != rhs->l_motor) {
    return false;
  }
  // g_stepper
  if (lhs->g_stepper != rhs->g_stepper) {
    return false;
  }
  // s_stepper
  if (lhs->s_stepper != rhs->s_stepper) {
    return false;
  }
  return true;
}

bool
ctrl_interface__msg__CtrlInterface__copy(
  const ctrl_interface__msg__CtrlInterface * input,
  ctrl_interface__msg__CtrlInterface * output)
{
  if (!input || !output) {
    return false;
  }
  // r_motor
  output->r_motor = input->r_motor;
  // l_motor
  output->l_motor = input->l_motor;
  // g_stepper
  output->g_stepper = input->g_stepper;
  // s_stepper
  output->s_stepper = input->s_stepper;
  return true;
}

ctrl_interface__msg__CtrlInterface *
ctrl_interface__msg__CtrlInterface__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ctrl_interface__msg__CtrlInterface * msg = (ctrl_interface__msg__CtrlInterface *)allocator.allocate(sizeof(ctrl_interface__msg__CtrlInterface), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ctrl_interface__msg__CtrlInterface));
  bool success = ctrl_interface__msg__CtrlInterface__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ctrl_interface__msg__CtrlInterface__destroy(ctrl_interface__msg__CtrlInterface * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ctrl_interface__msg__CtrlInterface__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ctrl_interface__msg__CtrlInterface__Sequence__init(ctrl_interface__msg__CtrlInterface__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ctrl_interface__msg__CtrlInterface * data = NULL;

  if (size) {
    data = (ctrl_interface__msg__CtrlInterface *)allocator.zero_allocate(size, sizeof(ctrl_interface__msg__CtrlInterface), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ctrl_interface__msg__CtrlInterface__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ctrl_interface__msg__CtrlInterface__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ctrl_interface__msg__CtrlInterface__Sequence__fini(ctrl_interface__msg__CtrlInterface__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ctrl_interface__msg__CtrlInterface__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ctrl_interface__msg__CtrlInterface__Sequence *
ctrl_interface__msg__CtrlInterface__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ctrl_interface__msg__CtrlInterface__Sequence * array = (ctrl_interface__msg__CtrlInterface__Sequence *)allocator.allocate(sizeof(ctrl_interface__msg__CtrlInterface__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ctrl_interface__msg__CtrlInterface__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ctrl_interface__msg__CtrlInterface__Sequence__destroy(ctrl_interface__msg__CtrlInterface__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ctrl_interface__msg__CtrlInterface__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ctrl_interface__msg__CtrlInterface__Sequence__are_equal(const ctrl_interface__msg__CtrlInterface__Sequence * lhs, const ctrl_interface__msg__CtrlInterface__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ctrl_interface__msg__CtrlInterface__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ctrl_interface__msg__CtrlInterface__Sequence__copy(
  const ctrl_interface__msg__CtrlInterface__Sequence * input,
  ctrl_interface__msg__CtrlInterface__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ctrl_interface__msg__CtrlInterface);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ctrl_interface__msg__CtrlInterface * data =
      (ctrl_interface__msg__CtrlInterface *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ctrl_interface__msg__CtrlInterface__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ctrl_interface__msg__CtrlInterface__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ctrl_interface__msg__CtrlInterface__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
