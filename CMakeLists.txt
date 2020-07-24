# CMake config
cmake_minimum_required(VERSION 3.16)
project(MyProject VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# build lib config
# set(BUILD_SHARED_LIBS True)

# add library config
# default static
# STATIC SHARED MODULE
add_library(
    dummy-lib STATIC
    dummy.hpp
    dummy.cpp
)

# Cxx standarad

# build output
add_executable(cpp-temp main.cpp)

# link library
target_link_libraries(cpp-temp PRIVATE dummy-lib)