// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from common_interface:msg/KeyCtrl.idl
// generated code does not contain a copyright notice
#include "common_interface/msg/detail/key_ctrl__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `manual_spd`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
common_interface__msg__KeyCtrl__init(common_interface__msg__KeyCtrl * msg)
{
  if (!msg) {
    return false;
  }
  // allow_nav
  // manual_spd
  if (!geometry_msgs__msg__Twist__init(&msg->manual_spd)) {
    common_interface__msg__KeyCtrl__fini(msg);
    return false;
  }
  return true;
}

void
common_interface__msg__KeyCtrl__fini(common_interface__msg__KeyCtrl * msg)
{
  if (!msg) {
    return;
  }
  // allow_nav
  // manual_spd
  geometry_msgs__msg__Twist__fini(&msg->manual_spd);
}

bool
common_interface__msg__KeyCtrl__are_equal(const common_interface__msg__KeyCtrl * lhs, const common_interface__msg__KeyCtrl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // allow_nav
  if (lhs->allow_nav != rhs->allow_nav) {
    return false;
  }
  // manual_spd
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->manual_spd), &(rhs->manual_spd)))
  {
    return false;
  }
  return true;
}

bool
common_interface__msg__KeyCtrl__copy(
  const common_interface__msg__KeyCtrl * input,
  common_interface__msg__KeyCtrl * output)
{
  if (!input || !output) {
    return false;
  }
  // allow_nav
  output->allow_nav = input->allow_nav;
  // manual_spd
  if (!geometry_msgs__msg__Twist__copy(
      &(input->manual_spd), &(output->manual_spd)))
  {
    return false;
  }
  return true;
}

common_interface__msg__KeyCtrl *
common_interface__msg__KeyCtrl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  common_interface__msg__KeyCtrl * msg = (common_interface__msg__KeyCtrl *)allocator.allocate(sizeof(common_interface__msg__KeyCtrl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(common_interface__msg__KeyCtrl));
  bool success = common_interface__msg__KeyCtrl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
common_interface__msg__KeyCtrl__destroy(common_interface__msg__KeyCtrl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    common_interface__msg__KeyCtrl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
common_interface__msg__KeyCtrl__Sequence__init(common_interface__msg__KeyCtrl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  common_interface__msg__KeyCtrl * data = NULL;

  if (size) {
    data = (common_interface__msg__KeyCtrl *)allocator.zero_allocate(size, sizeof(common_interface__msg__KeyCtrl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = common_interface__msg__KeyCtrl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        common_interface__msg__KeyCtrl__fini(&data[i - 1]);
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
common_interface__msg__KeyCtrl__Sequence__fini(common_interface__msg__KeyCtrl__Sequence * array)
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
      common_interface__msg__KeyCtrl__fini(&array->data[i]);
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

common_interface__msg__KeyCtrl__Sequence *
common_interface__msg__KeyCtrl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  common_interface__msg__KeyCtrl__Sequence * array = (common_interface__msg__KeyCtrl__Sequence *)allocator.allocate(sizeof(common_interface__msg__KeyCtrl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = common_interface__msg__KeyCtrl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
common_interface__msg__KeyCtrl__Sequence__destroy(common_interface__msg__KeyCtrl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    common_interface__msg__KeyCtrl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
common_interface__msg__KeyCtrl__Sequence__are_equal(const common_interface__msg__KeyCtrl__Sequence * lhs, const common_interface__msg__KeyCtrl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!common_interface__msg__KeyCtrl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
common_interface__msg__KeyCtrl__Sequence__copy(
  const common_interface__msg__KeyCtrl__Sequence * input,
  common_interface__msg__KeyCtrl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(common_interface__msg__KeyCtrl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    common_interface__msg__KeyCtrl * data =
      (common_interface__msg__KeyCtrl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!common_interface__msg__KeyCtrl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          common_interface__msg__KeyCtrl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!common_interface__msg__KeyCtrl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
