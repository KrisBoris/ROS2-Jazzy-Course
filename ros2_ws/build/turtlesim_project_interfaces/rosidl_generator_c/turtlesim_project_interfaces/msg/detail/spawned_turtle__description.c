// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtlesim_project_interfaces:msg/SpawnedTurtle.idl
// generated code does not contain a copyright notice

#include "turtlesim_project_interfaces/msg/detail/spawned_turtle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtlesim_project_interfaces
const rosidl_type_hash_t *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0xf1, 0x32, 0x49, 0x24, 0x81, 0x89, 0x1e,
      0x3f, 0xe8, 0x9f, 0x02, 0x26, 0x80, 0xdb, 0x7e,
      0x75, 0x98, 0x6c, 0xd7, 0x09, 0x12, 0xb1, 0xef,
      0xb8, 0x10, 0xdd, 0x26, 0x3b, 0xc1, 0x32, 0x01,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "turtlesim/msg/detail/pose__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t turtlesim__msg__Pose__EXPECTED_HASH = {1, {
    0x73, 0x9b, 0xeb, 0xa2, 0x6b, 0xcb, 0xa6, 0x92,
    0x04, 0x04, 0xba, 0x72, 0x2b, 0x7b, 0x83, 0x21,
    0x34, 0x85, 0x12, 0xf9, 0x2e, 0xa5, 0xbe, 0x23,
    0x5c, 0x47, 0x25, 0x19, 0x40, 0xdd, 0x8a, 0xa9,
  }};
#endif

static char turtlesim_project_interfaces__msg__SpawnedTurtle__TYPE_NAME[] = "turtlesim_project_interfaces/msg/SpawnedTurtle";
static char turtlesim__msg__Pose__TYPE_NAME[] = "turtlesim/msg/Pose";

// Define type names, field names, and default values
static char turtlesim_project_interfaces__msg__SpawnedTurtle__FIELD_NAME__name[] = "name";
static char turtlesim_project_interfaces__msg__SpawnedTurtle__FIELD_NAME__pose[] = "pose";

static rosidl_runtime_c__type_description__Field turtlesim_project_interfaces__msg__SpawnedTurtle__FIELDS[] = {
  {
    {turtlesim_project_interfaces__msg__SpawnedTurtle__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlesim_project_interfaces__msg__SpawnedTurtle__FIELD_NAME__pose, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlesim__msg__Pose__TYPE_NAME, 18, 18},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription turtlesim_project_interfaces__msg__SpawnedTurtle__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {turtlesim__msg__Pose__TYPE_NAME, 18, 18},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlesim_project_interfaces__msg__SpawnedTurtle__TYPE_NAME, 46, 46},
      {turtlesim_project_interfaces__msg__SpawnedTurtle__FIELDS, 2, 2},
    },
    {turtlesim_project_interfaces__msg__SpawnedTurtle__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&turtlesim__msg__Pose__EXPECTED_HASH, turtlesim__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = turtlesim__msg__Pose__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string name\n"
  "turtlesim/Pose pose";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlesim_project_interfaces__msg__SpawnedTurtle__TYPE_NAME, 46, 46},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlesim_project_interfaces__msg__SpawnedTurtle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlesim_project_interfaces__msg__SpawnedTurtle__get_individual_type_description_source(NULL),
    sources[1] = *turtlesim__msg__Pose__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
