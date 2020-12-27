cmake_minimum_required(VERSION 3.10)

project(AdventOfCode)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(src)
