include(FetchContent)
include(ExternalProject)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare (
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_SHALLOW true
  GIT_PROGRESS true
  GIT_TAG yaml-cpp-0.6.3
)

FetchContent_Declare (
  google_fruit
  GIT_REPOSITORY https://github.com/google/fruit.git
  GIT_SHALLOW true
  GIT_PROGRESS true
  gIT_TAG v3.6.0
)

# Why use manual population `FetchContent_Populate` instead of
# `FetchContent_MakeAvailable(yaml-cpp)`
# Because the allow for EXCLUDE_FROM_ALL help dont build other unneeded target of external project 
FetchContent_GetProperties(yaml-cpp)
if(NOT yaml-cpp_POPULATED) 
  FetchContent_Populate(yaml-cpp)
  add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# https://stackoverflow.com/questions/27086145/what-is-the-default-build-configuration-of-cmake
FetchContent_GetProperties(google_fruit)
if(NOT google_fruit_POPULATED) 
  FetchContent_Populate(google_fruit)
  set(CMAKE_BUILD_TYPE Debug)
  set(FRUIT_USES_BOOST false)
  add_subdirectory(${google_fruit_SOURCE_DIR} ${google_fruit_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()