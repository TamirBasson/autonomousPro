// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from common_interface:msg/SerComStruct.idl
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
#include "common_interface/msg/detail/ser_com_struct__struct.h"
#include "common_interface/msg/detail/ser_com_struct__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool common_interface__msg__ser_com_struct__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("common_interface.msg._ser_com_struct.SerComStruct", full_classname_dest, 49) == 0);
  }
  common_interface__msg__SerComStruct * ros_message = _ros_message;
  {  // pwm_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm_l");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pwm_l = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // pwm_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm_r");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pwm_r = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // dir_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "dir_l");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->dir_l = (Py_True == field);
    Py_DECREF(field);
  }
  {  // dir_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "dir_r");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->dir_r = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gear
    PyObject * field = PyObject_GetAttrString(_pymsg, "gear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gear = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * common_interface__msg__ser_com_struct__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SerComStruct */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("common_interface.msg._ser_com_struct");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SerComStruct");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  common_interface__msg__SerComStruct * ros_message = (common_interface__msg__SerComStruct *)raw_ros_message;
  {  // pwm_l
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->pwm_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pwm_r
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->pwm_r);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dir_l
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->dir_l ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dir_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dir_r
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->dir_r ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dir_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
