// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:action/CountUntil.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tutorial_interfaces/action/count_until.h"


#ifndef TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTIL__STRUCT_H_
#define TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTIL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_Goal
{
  int32_t target;
  bool simulate_failure;
} tutorial_interfaces__action__CountUntil_Goal;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_Goal.
typedef struct tutorial_interfaces__action__CountUntil_Goal__Sequence
{
  tutorial_interfaces__action__CountUntil_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_Result
{
  int32_t reached;
  rosidl_runtime_c__String message;
} tutorial_interfaces__action__CountUntil_Result;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_Result.
typedef struct tutorial_interfaces__action__CountUntil_Result__Sequence
{
  tutorial_interfaces__action__CountUntil_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_Feedback
{
  int32_t current;
} tutorial_interfaces__action__CountUntil_Feedback;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_Feedback.
typedef struct tutorial_interfaces__action__CountUntil_Feedback__Sequence
{
  tutorial_interfaces__action__CountUntil_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "tutorial_interfaces/action/detail/count_until__struct.h"

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  tutorial_interfaces__action__CountUntil_Goal goal;
} tutorial_interfaces__action__CountUntil_SendGoal_Request;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_SendGoal_Request.
typedef struct tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence
{
  tutorial_interfaces__action__CountUntil_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} tutorial_interfaces__action__CountUntil_SendGoal_Response;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_SendGoal_Response.
typedef struct tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence
{
  tutorial_interfaces__action__CountUntil_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tutorial_interfaces__action__CountUntil_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tutorial_interfaces__action__CountUntil_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tutorial_interfaces__action__CountUntil_SendGoal_Request__Sequence request;
  tutorial_interfaces__action__CountUntil_SendGoal_Response__Sequence response;
} tutorial_interfaces__action__CountUntil_SendGoal_Event;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_SendGoal_Event.
typedef struct tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence
{
  tutorial_interfaces__action__CountUntil_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} tutorial_interfaces__action__CountUntil_GetResult_Request;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_GetResult_Request.
typedef struct tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence
{
  tutorial_interfaces__action__CountUntil_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "tutorial_interfaces/action/detail/count_until__struct.h"

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_GetResult_Response
{
  int8_t status;
  tutorial_interfaces__action__CountUntil_Result result;
} tutorial_interfaces__action__CountUntil_GetResult_Response;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_GetResult_Response.
typedef struct tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence
{
  tutorial_interfaces__action__CountUntil_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tutorial_interfaces__action__CountUntil_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tutorial_interfaces__action__CountUntil_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tutorial_interfaces__action__CountUntil_GetResult_Request__Sequence request;
  tutorial_interfaces__action__CountUntil_GetResult_Response__Sequence response;
} tutorial_interfaces__action__CountUntil_GetResult_Event;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_GetResult_Event.
typedef struct tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence
{
  tutorial_interfaces__action__CountUntil_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "tutorial_interfaces/action/detail/count_until__struct.h"

/// Struct defined in action/CountUntil in the package tutorial_interfaces.
typedef struct tutorial_interfaces__action__CountUntil_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  tutorial_interfaces__action__CountUntil_Feedback feedback;
} tutorial_interfaces__action__CountUntil_FeedbackMessage;

// Struct for a sequence of tutorial_interfaces__action__CountUntil_FeedbackMessage.
typedef struct tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence
{
  tutorial_interfaces__action__CountUntil_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__action__CountUntil_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTIL__STRUCT_H_
