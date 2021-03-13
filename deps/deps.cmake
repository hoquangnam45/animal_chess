include(FetchContent)
include(ExternalProject)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare (
  rapidyaml
  GIT_REPOSITORY https://github.com/biojppm/rapidyaml
  GIT_SHALLOW true
  GIT_PROGRESS true
  GIT_TAG v0.1.0
)

FetchContent_Declare (
  google_fruit
  GIT_REPOSITORY https://github.com/google/fruit.git
  GIT_SHALLOW true
  GIT_PROGRESS true
  gIT_TAG v3.6.0
)

FetchContent_Declare (
  boost_win32
  URL https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.7z
  URL_HASH SHA256=3a8b314871646e7404886736273c053278ba71b11347f72d4751411d65d6d1a5
)

FetchContent_Declare (
  boost_linux
  URL https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.bz2
  URL_HASH SHA256=953db31e016db7bb207f11432bef7df100516eeb746843fa0486a222e3fd49cb
)

FetchContent_MakeAvailable(rapidyaml)

FetchContent_GetProperties(boost_win32)
FetchContent_GetProperties(boost_linux)
if (WIN32)
  FetchContent_MakeAvailable(boost_win32)
  set(boost_SOURCE_DIR ${boost_win32_SOURCE_DIR})
else()
  FetchContent_MakeAvailable(boost_linux)
  set(boost_SOURCE_DIR ${boost_linux_SOURCE_DIR})
endif()

FetchContent_GetProperties(google_fruit)
if(NOT google_fruit_POPULATED) 
  FetchContent_Populate(google_fruit)
  set(CMAKE_BUILD_TYPE Debug) # By default cmake will use this configuration
  set(Boost_INCLUDE_DIR ${boost_SOURCE_DIR})
  add_subdirectory(${google_fruit_SOURCE_DIR} ${google_fruit_BINARY_DIR})
  target_compile_definitions(fruit PUBLIC CMAKE_BUILD_TYPE=)
endif()