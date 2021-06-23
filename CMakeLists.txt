cmake_minimum_required(VERSION 3.0...3.16)

project(animal_chess LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# External dependecies with C++
include(deps/deps.cmake)

# Set c++ build level - For new feature of C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set directory for header file
include_directories(src/libs)
include_directories(src)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

# USING THIS PATTERN TO DISALLOW IT SCAN HEADER SEARCH TO COMPILE NECESSARY FILE WHICH LEAD TO LONG COMPILE TIME
set(CMAKE_AUTOUIC ON) # Compile ui file
set(CMAKE_AUTORCC ON) # Compile resource file
set(CMAKE_AUTOMOC ON) # Compile qt object macro
set(RESOURCE_FILES "resources/resourceMap.qrc")
set(LINGUIST_FILES "animal_chess_vi_VN.ts") # List of different version of linguist files
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/src ${LINGUIST_FILES})

file(GLOB_RECURSE SOURCE_FILES 
  "src/*.cpp"
)
if(ANDROID)
  add_library(animal_chess SHARED
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    src/mainwindow.h
    ${SOURCE_FILES}
    ${LINGUIST_FILES}
    ${RESOURCE_FILES}
  )
else()
  add_executable(animal_chess
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    src/mainwindow.h
    ${SOURCE_FILES}
    ${LINGUIST_FILES}
    ${RESOURCE_FILES}
  )
endif()

target_link_libraries(animal_chess PRIVATE Qt${QT_VERSION_MAJOR}::Widgets yaml-cpp fruit)

