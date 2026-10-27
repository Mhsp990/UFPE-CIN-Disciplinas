// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:action/CountUntil.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/action/detail/count_until__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tutorial_interfaces__action__CountUntil_Goal__init(tutorial_interfaces__action__CountUntil_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target
  // simulate_failure
  return true;
}

void
tutorial_interfaces__action__CountUntil_Goal__fini(tutorial_interfaces__action__CountUntil_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target
  // simulate_failure
}

bool
tutorial_interfaces__action__CountUntil_Goal__are_equal(const tutorial_interfaces__action__CountUntil_Goal * lhs, const tutorial_interfaces__action__CountUntil_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target
  if (lhs->target != rhs->target) {
    return false;
  }
  // simulate_failure
  if (lhs->simulate_failure != rhs->simulate_failure) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_Goal__copy(
  const tutorial_interfaces__action__CountUntil_Goal * input,
  tutorial_interfaces__action__CountUntil_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target
  output->target = input->target;
  // simulate_failure
  output->simulate_failure = input->simulate_failure;
  return true;
}

tutorial_interfaces__action__CountUntil_Goal *
tutorial_interfaces__action__CountUntil_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Goal * msg = (tutorial_interfaces__action__CountUntil_Goal *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_Goal));
  bool success = tutorial_interfaces__action__CountUntil_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_Goal__destroy(tutorial_interfaces__action__CountUntil_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_Goal__Sequence__init(tutorial_interfaces__action__CountUntil_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Goal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_Goal)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_Goal *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_Goal__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_Goal__Sequence__fini(tutorial_interfaces__action__CountUntil_Goal__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_Goal__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_Goal__Sequence *
tutorial_interfaces__action__CountUntil_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Goal__Sequence * array = (tutorial_interfaces__action__CountUntil_Goal__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_Goal__Sequence__destroy(tutorial_interfaces__action__CountUntil_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_Goal__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_Goal__Sequence * lhs, const tutorial_interfaces__action__CountUntil_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_Goal__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_Goal__Sequence * input,
  tutorial_interfaces__action__CountUntil_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_Goal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_Goal * data =
      (tutorial_interfaces__action__CountUntil_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
tutorial_interfaces__action__CountUntil_Result__init(tutorial_interfaces__action__CountUntil_Result * msg)
{
  if (!msg) {
    return false;
  }
  // reached
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    tutorial_interfaces__action__CountUntil_Result__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_Result__fini(tutorial_interfaces__action__CountUntil_Result * msg)
{
  if (!msg) {
    return;
  }
  // reached
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
tutorial_interfaces__action__CountUntil_Result__are_equal(const tutorial_interfaces__action__CountUntil_Result * lhs, const tutorial_interfaces__action__CountUntil_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // reached
  if (lhs->reached != rhs->reached) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_Result__copy(
  const tutorial_interfaces__action__CountUntil_Result * input,
  tutorial_interfaces__action__CountUntil_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // reached
  output->reached = input->reached;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_Result *
tutorial_interfaces__action__CountUntil_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Result * msg = (tutorial_interfaces__action__CountUntil_Result *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_Result));
  bool success = tutorial_interfaces__action__CountUntil_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_Result__destroy(tutorial_interfaces__action__CountUntil_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_Result__Sequence__init(tutorial_interfaces__action__CountUntil_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Result * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_Result)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_Result *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_Result__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_Result__Sequence__fini(tutorial_interfaces__action__CountUntil_Result__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_Result__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_Result__Sequence *
tutorial_interfaces__action__CountUntil_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Result__Sequence * array = (tutorial_interfaces__action__CountUntil_Result__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_Result__Sequence__destroy(tutorial_interfaces__action__CountUntil_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_Result__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_Result__Sequence * lhs, const tutorial_interfaces__action__CountUntil_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_Result__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_Result__Sequence * input,
  tutorial_interfaces__action__CountUntil_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_Result)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_Result * data =
      (tutorial_interfaces__action__CountUntil_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
tutorial_interfaces__action__CountUntil_Feedback__init(tutorial_interfaces__action__CountUntil_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current
  return true;
}

void
tutorial_interfaces__action__CountUntil_Feedback__fini(tutorial_interfaces__action__CountUntil_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current
}

bool
tutorial_interfaces__action__CountUntil_Feedback__are_equal(const tutorial_interfaces__action__CountUntil_Feedback * lhs, const tutorial_interfaces__action__CountUntil_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_Feedback__copy(
  const tutorial_interfaces__action__CountUntil_Feedback * input,
  tutorial_interfaces__action__CountUntil_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current
  output->current = input->current;
  return true;
}

tutorial_interfaces__action__CountUntil_Feedback *
tutorial_interfaces__action__CountUntil_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Feedback * msg = (tutorial_interfaces__action__CountUntil_Feedback *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_Feedback));
  bool success = tutorial_interfaces__action__CountUntil_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_Feedback__destroy(tutorial_interfaces__action__CountUntil_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_Feedback__Sequence__init(tutorial_interfaces__action__CountUntil_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Feedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_Feedback)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_Feedback *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_Feedback__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_Feedback__Sequence__fini(tutorial_interfaces__action__CountUntil_Feedback__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_Feedback__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_Feedback__Sequence *
tutorial_interfaces__action__CountUntil_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_Feedback__Sequence * array = (tutorial_interfaces__action__CountUntil_Feedback__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_Feedback__Sequence__destroy(tutorial_interfaces__action__CountUntil_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_Feedback__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_Feedback__Sequence * lhs, const tutorial_interfaces__action__CountUntil_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_Feedback__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_Feedback__Sequence * input,
  tutorial_interfaces__action__CountUntil_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_Feedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_Feedback * data =
      (tutorial_interfaces__action__CountUntil_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "tutorial_interfaces/action/detail/count_until__functions.h"

bool
tutorial_interfaces__action__CountUntil_SendGoal_Request__init(tutorial_interfaces__action__CountUntil_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!tutorial_interfaces__action__CountUntil_Goal__init(&msg->goal)) {
    tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(tutorial_interfaces__action__CountUntil_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  tutorial_interfaces__action__CountUntil_Goal__fini(&msg->goal);
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Request__are_equal(const tutorial_interfaces__action__CountUntil_SendGoal_Request * lhs, const tutorial_interfaces__action__CountUntil_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!tutorial_interfaces__action__CountUntil_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Request__copy(
  const tutorial_interfaces__action__CountUntil_SendGoal_Request * input,
  tutorial_interfaces__action__CountUntil_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!tutorial_interfaces__action__CountUntil_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_SendGoal_Request *
tutorial_interfaces__action__CountUntil_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Request * msg = (tutorial_interfaces__action__CountUntil_SendGoal_Request *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request));
  bool success = tutorial_interfaces__action__CountUntil_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Request__destroy(tutorial_interfaces__action__CountUntil_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__init(tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_SendGoal_Request *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__fini(tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence *
tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * array = (tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__destroy(tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * lhs, const tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * input,
  tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_SendGoal_Request * data =
      (tutorial_interfaces__action__CountUntil_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
tutorial_interfaces__action__CountUntil_SendGoal_Response__init(tutorial_interfaces__action__CountUntil_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    tutorial_interfaces__action__CountUntil_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Response__fini(tutorial_interfaces__action__CountUntil_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Response__are_equal(const tutorial_interfaces__action__CountUntil_SendGoal_Response * lhs, const tutorial_interfaces__action__CountUntil_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Response__copy(
  const tutorial_interfaces__action__CountUntil_SendGoal_Response * input,
  tutorial_interfaces__action__CountUntil_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_SendGoal_Response *
tutorial_interfaces__action__CountUntil_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Response * msg = (tutorial_interfaces__action__CountUntil_SendGoal_Response *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response));
  bool success = tutorial_interfaces__action__CountUntil_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Response__destroy(tutorial_interfaces__action__CountUntil_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__init(tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_SendGoal_Response *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_SendGoal_Response__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__fini(tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_SendGoal_Response__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence *
tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * array = (tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__destroy(tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * lhs, const tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * input,
  tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_SendGoal_Response * data =
      (tutorial_interfaces__action__CountUntil_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "tutorial_interfaces/action/detail/count_until__functions.h"

bool
tutorial_interfaces__action__CountUntil_SendGoal_Event__init(tutorial_interfaces__action__CountUntil_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(tutorial_interfaces__action__CountUntil_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Event__are_equal(const tutorial_interfaces__action__CountUntil_SendGoal_Event * lhs, const tutorial_interfaces__action__CountUntil_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Event__copy(
  const tutorial_interfaces__action__CountUntil_SendGoal_Event * input,
  tutorial_interfaces__action__CountUntil_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_SendGoal_Event *
tutorial_interfaces__action__CountUntil_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Event * msg = (tutorial_interfaces__action__CountUntil_SendGoal_Event *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event));
  bool success = tutorial_interfaces__action__CountUntil_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Event__destroy(tutorial_interfaces__action__CountUntil_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__init(tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_SendGoal_Event *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__fini(tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence *
tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * array = (tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__destroy(tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * lhs, const tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * input,
  tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_SendGoal_Event * data =
      (tutorial_interfaces__action__CountUntil_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
tutorial_interfaces__action__CountUntil_GetResult_Request__init(tutorial_interfaces__action__CountUntil_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    tutorial_interfaces__action__CountUntil_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Request__fini(tutorial_interfaces__action__CountUntil_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Request__are_equal(const tutorial_interfaces__action__CountUntil_GetResult_Request * lhs, const tutorial_interfaces__action__CountUntil_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Request__copy(
  const tutorial_interfaces__action__CountUntil_GetResult_Request * input,
  tutorial_interfaces__action__CountUntil_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_GetResult_Request *
tutorial_interfaces__action__CountUntil_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Request * msg = (tutorial_interfaces__action__CountUntil_GetResult_Request *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request));
  bool success = tutorial_interfaces__action__CountUntil_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Request__destroy(tutorial_interfaces__action__CountUntil_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__init(tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_GetResult_Request *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_GetResult_Request__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__fini(tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_GetResult_Request__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence *
tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * array = (tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__destroy(tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * lhs, const tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * input,
  tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_GetResult_Request * data =
      (tutorial_interfaces__action__CountUntil_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "tutorial_interfaces/action/detail/count_until__functions.h"

bool
tutorial_interfaces__action__CountUntil_GetResult_Response__init(tutorial_interfaces__action__CountUntil_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!tutorial_interfaces__action__CountUntil_Result__init(&msg->result)) {
    tutorial_interfaces__action__CountUntil_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Response__fini(tutorial_interfaces__action__CountUntil_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  tutorial_interfaces__action__CountUntil_Result__fini(&msg->result);
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Response__are_equal(const tutorial_interfaces__action__CountUntil_GetResult_Response * lhs, const tutorial_interfaces__action__CountUntil_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!tutorial_interfaces__action__CountUntil_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Response__copy(
  const tutorial_interfaces__action__CountUntil_GetResult_Response * input,
  tutorial_interfaces__action__CountUntil_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!tutorial_interfaces__action__CountUntil_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_GetResult_Response *
tutorial_interfaces__action__CountUntil_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Response * msg = (tutorial_interfaces__action__CountUntil_GetResult_Response *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response));
  bool success = tutorial_interfaces__action__CountUntil_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Response__destroy(tutorial_interfaces__action__CountUntil_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__init(tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_GetResult_Response *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_GetResult_Response__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__fini(tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_GetResult_Response__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence *
tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * array = (tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__destroy(tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * lhs, const tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * input,
  tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_GetResult_Response * data =
      (tutorial_interfaces__action__CountUntil_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "tutorial_interfaces/action/detail/count_until__functions.h"

bool
tutorial_interfaces__action__CountUntil_GetResult_Event__init(tutorial_interfaces__action__CountUntil_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    tutorial_interfaces__action__CountUntil_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__init(&msg->request, 0)) {
    tutorial_interfaces__action__CountUntil_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__init(&msg->response, 0)) {
    tutorial_interfaces__action__CountUntil_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Event__fini(tutorial_interfaces__action__CountUntil_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__fini(&msg->request);
  // response
  tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__fini(&msg->response);
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Event__are_equal(const tutorial_interfaces__action__CountUntil_GetResult_Event * lhs, const tutorial_interfaces__action__CountUntil_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Event__copy(
  const tutorial_interfaces__action__CountUntil_GetResult_Event * input,
  tutorial_interfaces__action__CountUntil_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_GetResult_Event *
tutorial_interfaces__action__CountUntil_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Event * msg = (tutorial_interfaces__action__CountUntil_GetResult_Event *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event));
  bool success = tutorial_interfaces__action__CountUntil_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Event__destroy(tutorial_interfaces__action__CountUntil_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__init(tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_GetResult_Event *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_GetResult_Event__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__fini(tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_GetResult_Event__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence *
tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * array = (tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__destroy(tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * lhs, const tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * input,
  tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_GetResult_Event * data =
      (tutorial_interfaces__action__CountUntil_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "tutorial_interfaces/action/detail/count_until__functions.h"

bool
tutorial_interfaces__action__CountUntil_FeedbackMessage__init(tutorial_interfaces__action__CountUntil_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!tutorial_interfaces__action__CountUntil_Feedback__init(&msg->feedback)) {
    tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(tutorial_interfaces__action__CountUntil_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  tutorial_interfaces__action__CountUntil_Feedback__fini(&msg->feedback);
}

bool
tutorial_interfaces__action__CountUntil_FeedbackMessage__are_equal(const tutorial_interfaces__action__CountUntil_FeedbackMessage * lhs, const tutorial_interfaces__action__CountUntil_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!tutorial_interfaces__action__CountUntil_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_FeedbackMessage__copy(
  const tutorial_interfaces__action__CountUntil_FeedbackMessage * input,
  tutorial_interfaces__action__CountUntil_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!tutorial_interfaces__action__CountUntil_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__action__CountUntil_FeedbackMessage *
tutorial_interfaces__action__CountUntil_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_FeedbackMessage * msg = (tutorial_interfaces__action__CountUntil_FeedbackMessage *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage));
  bool success = tutorial_interfaces__action__CountUntil_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__action__CountUntil_FeedbackMessage__destroy(tutorial_interfaces__action__CountUntil_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__init(tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_FeedbackMessage * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage)) {
      return false;
    }
    data = (tutorial_interfaces__action__CountUntil_FeedbackMessage *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__action__CountUntil_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(&data[i - 1]);
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
tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__fini(tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * array)
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
      tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(&array->data[i]);
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

tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence *
tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * array = (tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__destroy(tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__are_equal(const tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * lhs, const tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence__copy(
  const tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * input,
  tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__action__CountUntil_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__action__CountUntil_FeedbackMessage * data =
      (tutorial_interfaces__action__CountUntil_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__action__CountUntil_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__action__CountUntil_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__action__CountUntil_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
