# Basic sanity check
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# Set up project
project(axcend VERSION 0.1 LANGUAGES CXX)

# Set compiler flags (bad practice, TODO: Fix this)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g")

# Executable
set(EXECUTABLE_NAME main)

add_subdirectory(src/)
