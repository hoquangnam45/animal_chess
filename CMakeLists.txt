cmake_minimum_required(VERSION 3.16)

project(animal_chess LANGUAGES CXX)

# Export compile_commands.json for clangd for code suggestion in some ide like vscode, but only with Makefile-like generator
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# To use clang compiler clang-cl on windows: Set environment using vcvarsall.bat first
## This is intend for gcc-compatible(clang, gcc) compiler
#if (MSVC)
#  add_compile_options(-Wno-missing-declarations)
#else()
#  # lots of warnings and all warnings as errors
#  add_compile_options(-Wno-missing-declarations)
#endif()

# Set c++ build level - For new feature of C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# External dependecies with C++
include(deps/conan.cmake)

# Set directory for header file
include_directories(src/libs)
include_directories(src)

# USING THIS PATTERN TO DISALLOW IT SCAN HEADER SEARCH TO COMPILE NECESSARY FILE WHICH LEAD TO LONG COMPILE TIME
set(CMAKE_AUTOUIC ON) # Compile ui file
set(CMAKE_AUTORCC ON) # Compile resource file
set(CMAKE_AUTOMOC ON) # Compile qt object macro

find_package(Qt6 COMPONENTS Widgets LinguistTools REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.ui")
set(RESOURCE_FILES "resources/resourceMap.qrc")
set(LINGUIST_FILES "animal_chess_vi_VN.ts" src/libs/component/dropper/dropper.cpp src/libs/component/dropper/dropper.h src/libs/logic/validMoveSuggester/ValidMoveSuggester.cpp src/libs/logic/validMoveSuggester/ValidMoveSuggester.h) # List of different version of linguist files
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/src ${LINGUIST_FILES})

if(ANDROID)
  add_library(animal_chess SHARED
    ${SOURCE_FILES}
    ${LINGUIST_FILES}
    ${RESOURCE_FILES}
  )
else()
  add_executable(animal_chess
    ${SOURCE_FILES}
    ${LINGUIST_FILES}
    ${RESOURCE_FILES}
  )
endif()

target_link_libraries(animal_chess PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${CONAN_LIBS})

