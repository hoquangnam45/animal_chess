# Dependencies management with FetchContent
#include(FetchContent)
#include(ExternalProject)
#set(FETCHCONTENT_QUIET FALSE)
#
#FetchContent_Declare (
#  yaml-cpp
#  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
#  GIT_SHALLOW true
#  GIT_PROGRESS true
#  GIT_TAG yaml-cpp-0.7.0
#)
#
#FetchContent_Declare (
#  google_fruit
#  GIT_REPOSITORY https://github.com/google/fruit.git
#  GIT_SHALLOW true
#  GIT_PROGRESS true
#  GIT_TAG v3.6.0
#)
#
#if (WIN32)
#  FetchContent_Declare (
#    boost
#    URL "https://boostorg.jfrog.io/artifactory/main/release/1.76.0/source/boost_1_76_0.zip"
#    URL_HASH "SHA256=0fd43bb53580ca54afc7221683dfe8c6e3855b351cd6dce53b1a24a7d7fbeedd"
#  )
#else()
#  FetchContent_Declare (
#    boost
#    URL "https://boostorg.jfrog.io/artifactory/main/release/1.76.0/source/boost_1_76_0.tar.bz2"
#    URL_HASH "SHA256=f0397ba6e982c4450f27bf32a2a83292aba035b827a5623a14636ea583318c41"
#  )
#endif()
#
#FetchContent_Declare (
#    smart_enums
#    GIT_REPOSITORY https://github.com/Microsoft/vcpkg.git
#)
#
## Why use manual population `FetchContent_Populate` instead of
## `FetchContent_MakeAvailable(yaml-cpp)`
## Because the allow for EXCLUDE_FROM_ALL help dont build other unneeded target of external project when execute `build --target=all`
#FetchContent_GetProperties(yaml-cpp)
#if(NOT yaml-cpp_POPULATED)
#  FetchContent_Populate(yaml-cpp)
#  add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR} EXCLUDE_FROM_ALL)
#endif()
#
#FetchContent_GetProperties(boost)
#if(NOT boost_POPULATED)
#  FetchContent_Populate(boost)
#  include_directories(${boost_SOURCE_DIR})
#endif()
#
## https://stackoverflow.com/questions/27086145/what-is-the-default-build-configuration-of-cmake
#FetchContent_GetProperties(google_fruit)
#if(NOT google_fruit_POPULATED)
#  FetchContent_Populate(google_fruit)
#  set(CMAKE_BUILD_TYPE Debug)
#  set(FRUIT_USES_BOOST true)
#  set(Boost_INCLUDE_DIR ${boost_SOURCE_DIR})
#  add_subdirectory(${google_fruit_SOURCE_DIR} ${google_fruit_BINARY_DIR} EXCLUDE_FROM_ALL)
#endif()