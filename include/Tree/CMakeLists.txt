﻿# CMakeList.txt : CMake project for Tree, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Tree")

# Add source to this project's executable.
add_executable (Tree "Tree.cpp" "Tree.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Tree PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
