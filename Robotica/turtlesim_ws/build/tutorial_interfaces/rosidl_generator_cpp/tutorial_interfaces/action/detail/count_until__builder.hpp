// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:action/CountUntil.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tutorial_interfaces/action/count_until.hpp"


#ifndef TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTIL__BUILDER_HPP_
#define TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTIL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/action/detail/count_until__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_Goal_simulate_failure
{
public:
  explicit Init_CountUntil_Goal_simulate_failure(::tutorial_interfaces::action::CountUntil_Goal & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_Goal simulate_failure(::tutorial_interfaces::action::CountUntil_Goal::_simulate_failure_type arg)
  {
    msg_.simulate_failure = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_Goal msg_;
};

class Init_CountUntil_Goal_target
{
public:
  Init_CountUntil_Goal_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_Goal_simulate_failure target(::tutorial_interfaces::action::CountUntil_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_CountUntil_Goal_simulate_failure(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_Goal>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_Goal_target();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_Result_message
{
public:
  explicit Init_CountUntil_Result_message(::tutorial_interfaces::action::CountUntil_Result & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_Result message(::tutorial_interfaces::action::CountUntil_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_Result msg_;
};

class Init_CountUntil_Result_reached
{
public:
  Init_CountUntil_Result_reached()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_Result_message reached(::tutorial_interfaces::action::CountUntil_Result::_reached_type arg)
  {
    msg_.reached = std::move(arg);
    return Init_CountUntil_Result_message(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_Result>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_Result_reached();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_Feedback_current
{
public:
  Init_CountUntil_Feedback_current()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::action::CountUntil_Feedback current(::tutorial_interfaces::action::CountUntil_Feedback::_current_type arg)
  {
    msg_.current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_Feedback>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_Feedback_current();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_SendGoal_Request_goal
{
public:
  explicit Init_CountUntil_SendGoal_Request_goal(::tutorial_interfaces::action::CountUntil_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_SendGoal_Request goal(::tutorial_interfaces::action::CountUntil_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Request msg_;
};

class Init_CountUntil_SendGoal_Request_goal_id
{
public:
  Init_CountUntil_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_SendGoal_Request_goal goal_id(::tutorial_interfaces::action::CountUntil_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_CountUntil_SendGoal_Request_goal(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_SendGoal_Request>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_SendGoal_Request_goal_id();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_SendGoal_Response_stamp
{
public:
  explicit Init_CountUntil_SendGoal_Response_stamp(::tutorial_interfaces::action::CountUntil_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_SendGoal_Response stamp(::tutorial_interfaces::action::CountUntil_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Response msg_;
};

class Init_CountUntil_SendGoal_Response_accepted
{
public:
  Init_CountUntil_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_SendGoal_Response_stamp accepted(::tutorial_interfaces::action::CountUntil_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_CountUntil_SendGoal_Response_stamp(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_SendGoal_Response>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_SendGoal_Response_accepted();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_SendGoal_Event_response
{
public:
  explicit Init_CountUntil_SendGoal_Event_response(::tutorial_interfaces::action::CountUntil_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_SendGoal_Event response(::tutorial_interfaces::action::CountUntil_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Event msg_;
};

class Init_CountUntil_SendGoal_Event_request
{
public:
  explicit Init_CountUntil_SendGoal_Event_request(::tutorial_interfaces::action::CountUntil_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_CountUntil_SendGoal_Event_response request(::tutorial_interfaces::action::CountUntil_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_CountUntil_SendGoal_Event_response(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Event msg_;
};

class Init_CountUntil_SendGoal_Event_info
{
public:
  Init_CountUntil_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_SendGoal_Event_request info(::tutorial_interfaces::action::CountUntil_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_CountUntil_SendGoal_Event_request(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_SendGoal_Event>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_SendGoal_Event_info();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_GetResult_Request_goal_id
{
public:
  Init_CountUntil_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::action::CountUntil_GetResult_Request goal_id(::tutorial_interfaces::action::CountUntil_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_GetResult_Request>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_GetResult_Request_goal_id();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_GetResult_Response_result
{
public:
  explicit Init_CountUntil_GetResult_Response_result(::tutorial_interfaces::action::CountUntil_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_GetResult_Response result(::tutorial_interfaces::action::CountUntil_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_GetResult_Response msg_;
};

class Init_CountUntil_GetResult_Response_status
{
public:
  Init_CountUntil_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_GetResult_Response_result status(::tutorial_interfaces::action::CountUntil_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_CountUntil_GetResult_Response_result(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_GetResult_Response>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_GetResult_Response_status();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_GetResult_Event_response
{
public:
  explicit Init_CountUntil_GetResult_Event_response(::tutorial_interfaces::action::CountUntil_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_GetResult_Event response(::tutorial_interfaces::action::CountUntil_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_GetResult_Event msg_;
};

class Init_CountUntil_GetResult_Event_request
{
public:
  explicit Init_CountUntil_GetResult_Event_request(::tutorial_interfaces::action::CountUntil_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_CountUntil_GetResult_Event_response request(::tutorial_interfaces::action::CountUntil_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_CountUntil_GetResult_Event_response(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_GetResult_Event msg_;
};

class Init_CountUntil_GetResult_Event_info
{
public:
  Init_CountUntil_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_GetResult_Event_request info(::tutorial_interfaces::action::CountUntil_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_CountUntil_GetResult_Event_request(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_GetResult_Event>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_GetResult_Event_info();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntil_FeedbackMessage_feedback
{
public:
  explicit Init_CountUntil_FeedbackMessage_feedback(::tutorial_interfaces::action::CountUntil_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntil_FeedbackMessage feedback(::tutorial_interfaces::action::CountUntil_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_FeedbackMessage msg_;
};

class Init_CountUntil_FeedbackMessage_goal_id
{
public:
  Init_CountUntil_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntil_FeedbackMessage_feedback goal_id(::tutorial_interfaces::action::CountUntil_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_CountUntil_FeedbackMessage_feedback(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntil_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntil_FeedbackMessage>()
{
  return tutorial_interfaces::action::builder::Init_CountUntil_FeedbackMessage_goal_id();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTIL__BUILDER_HPP_
