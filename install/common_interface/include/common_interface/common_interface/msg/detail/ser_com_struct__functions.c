// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from common_interface:msg/SerComStruct.idl
// generated code does not contain a copyright notice
#include "common_interface/msg/detail/ser_com_struct__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
common_interface__msg__SerComStruct__init(common_interface__msg__SerComStruct * msg)
{
  if (!msg) {
    return false;
  }
  // pwm_l
  // pwm_r
  // dir_l
  // dir_r
  // gear
  return true;
}

void
common_interface__msg__SerComStruct__fini(common_interface__msg__SerComStruct * msg)
{
  if (!msg) {
    return;
  }
  // pwm_l
  // pwm_r
  // dir_l
  // dir_r
  // gear
}

bool
common_interface__msg__SerComStruct__are_equal(const common_interface__msg__SerComStruct * lhs, const common_interface__msg__SerComStruct * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pwm_l
  if (lhs->pwm_l != rhs->pwm_l) {
    return false;
  }
  // pwm_r
  if (lhs->pwm_r != rhs->pwm_r) {
    return false;
  }
  // dir_l
  if (lhs->dir_l != rhs->dir_l) {
    return false;
  }
  // dir_r
  if (lhs->dir_r != rhs->dir_r) {
    return false;
  }
  // gear
  if (lhs->gear != rhs->gear) {
    return false;
  }
  return true;
}

bool
common_interface__msg__SerComStruct__copy(
  const common_interface__msg__SerComStruct * input,
  common_interface__msg__SerComStruct * output)
{
  if (!input || !output) {
    return false;
  }
  // pwm_l
  output->pwm_l = input->pwm_l;
  // pwm_r
  output->pwm_r = input->pwm_r;
  // dir_l
  output->dir_l = input->dir_l;
  // dir_r
  output->dir_r = input->dir_r;
  // gear
  output->gear = input->gear;
  return true;
}

common_interface__msg__SerComStruct *
common_interface__msg__SerComStruct__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  common_interface__msg__SerComStruct * msg = (common_interface__msg__SerComStruct *)allocator.allocate(sizeof(common_interface__msg__SerComStruct), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(common_interface__msg__SerComStruct));
  bool success = common_interface__msg__SerComStruct__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
common_interface__msg__SerComStruct__destroy(common_interface__msg__SerComStruct * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    common_interface__msg__SerComStruct__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
common_interface__msg__SerComStruct__Sequence__init(common_interface__msg__SerComStruct__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  common_interface__msg__SerComStruct * data = NULL;

  if (size) {
    data = (common_interface__msg__SerComStruct *)allocator.zero_allocate(size, sizeof(common_interface__msg__SerComStruct), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = common_interface__msg__SerComStruct__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        common_interface__msg__SerComStruct__fini(&data[i - 1]);
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
common_interface__msg__SerComStruct__Sequence__fini(common_interface__msg__SerComStruct__Sequence * array)
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
      common_interface__msg__SerComStruct__fini(&array->data[i]);
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

common_interface__msg__SerComStruct__Sequence *
common_interface__msg__SerComStruct__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  common_interface__msg__SerComStruct__Sequence * array = (common_interface__msg__SerComStruct__Sequence *)allocator.allocate(sizeof(common_interface__msg__SerComStruct__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = common_interface__msg__SerComStruct__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
common_interface__msg__SerComStruct__Sequence__destroy(common_interface__msg__SerComStruct__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    common_interface__msg__SerComStruct__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
common_interface__msg__SerComStruct__Sequence__are_equal(const common_interface__msg__SerComStruct__Sequence * lhs, const common_interface__msg__SerComStruct__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!common_interface__msg__SerComStruct__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
common_interface__msg__SerComStruct__Sequence__copy(
  const common_interface__msg__SerComStruct__Sequence * input,
  common_interface__msg__SerComStruct__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(common_interface__msg__SerComStruct);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    common_interface__msg__SerComStruct * data =
      (common_interface__msg__SerComStruct *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!common_interface__msg__SerComStruct__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          common_interface__msg__SerComStruct__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!common_interface__msg__SerComStruct__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
