include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
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
  boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_SHALLOW true
  GIT_PROGRESS true
  GIT_TAG boost-1.75.0
  GIT_SUBMODULES "tools/build"
)

FetchContent_MakeAvailable(rapidyaml)
FetchContent_GetProperties(boost)
if (NOT boost_POPULATED)
  FetchContent_Populate(boost)
  if(WIN32)
  message(>>>>>>>>>>>>>>>>>>>>>>>>)
    execute_process(COMMAND "bootstrap.bat" WORKING_DIRECTORY ${boost_SOURCE_DIR})
    message(<<<<<<<<<<<<<<<<<<<<<<)
  else()
    execute_process(COMMAND "bootstrap.sh" WORKING_DIRECTORY ${boost_SOURCE_DIR})
  endif()
endif()

FetchContent_GetProperties(google_fruit)
if(NOT google_fruit_POPULATED) 
  FetchContent_Populate(google_fruit)
  set(CMAKE_BUILD_TYPE MinSizeRel)
  add_subdirectory(${google_fruit_SOURCE_DIR} ${google_fruit_BINARY_DIR})
endif()