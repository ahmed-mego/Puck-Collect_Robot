// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ctrl_interface:msg/CtrlInterface.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ctrl_interface/msg/detail/ctrl_interface__struct.h"
#include "ctrl_interface/msg/detail/ctrl_interface__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ctrl_interface__msg__ctrl_interface__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ctrl_interface.msg._ctrl_interface.CtrlInterface", full_classname_dest, 48) == 0);
  }
  ctrl_interface__msg__CtrlInterface * ros_message = _ros_message;
  {  // r_motor
    PyObject * field = PyObject_GetAttrString(_pymsg, "r_motor");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->r_motor = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // l_motor
    PyObject * field = PyObject_GetAttrString(_pymsg, "l_motor");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->l_motor = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // g_stepper
    PyObject * field = PyObject_GetAttrString(_pymsg, "g_stepper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->g_stepper = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // s_stepper
    PyObject * field = PyObject_GetAttrString(_pymsg, "s_stepper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->s_stepper = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ctrl_interface__msg__ctrl_interface__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CtrlInterface */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ctrl_interface.msg._ctrl_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CtrlInterface");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ctrl_interface__msg__CtrlInterface * ros_message = (ctrl_interface__msg__CtrlInterface *)raw_ros_message;
  {  // r_motor
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->r_motor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "r_motor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // l_motor
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->l_motor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "l_motor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // g_stepper
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->g_stepper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "g_stepper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // s_stepper
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->s_stepper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "s_stepper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
