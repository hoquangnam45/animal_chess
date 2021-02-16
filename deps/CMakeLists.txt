include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  rapidyaml
  GIT_REPOSITORY https://github.com/biojppm/rapidyaml
  GIT_SHALLOW true
  GIT_PROGRESS true
  GIT_TAG v0.1.0
  SOURCE_DIR ../deps/rapidyaml
)

FetchContent_MakeAvailable(rapidyaml) 