// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_project_interfaces/msg/spawned_turtle.hpp"


#ifndef TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__STRUCT_HPP_
#define TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "turtlesim/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turtlesim_project_interfaces__msg__SpawnedTurtle __attribute__((deprecated))
#else
# define DEPRECATED__turtlesim_project_interfaces__msg__SpawnedTurtle __declspec(deprecated)
#endif

namespace turtlesim_project_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpawnedTurtle_
{
  using Type = SpawnedTurtle_<ContainerAllocator>;

  explicit SpawnedTurtle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit SpawnedTurtle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _pose_type =
    turtlesim::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__pose(
    const turtlesim::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtlesim_project_interfaces__msg__SpawnedTurtle
    std::shared_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtlesim_project_interfaces__msg__SpawnedTurtle
    std::shared_ptr<turtlesim_project_interfaces::msg::SpawnedTurtle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpawnedTurtle_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpawnedTurtle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpawnedTurtle_

// alias to use template instance with default allocator
using SpawnedTurtle =
  turtlesim_project_interfaces::msg::SpawnedTurtle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtlesim_project_interfaces

#endif  // TURTLESIM_PROJECT_INTERFACES__MSG__DETAIL__SPAWNED_TURTLE__STRUCT_HPP_
