﻿# CMakeList.txt : CMake project for SequentialClasses, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SequentialClasses")

# Add source to this project's executable.
add_executable (SequentialClasses "SequentialClasses.cpp" "SequentialClasses.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SequentialClasses PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
