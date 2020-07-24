# CMake config
cmake_minimum_required(VERSION 3.16)

set(This demo)
project(${This} VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
# specify the C standard
set(CMAKE_C_STANDARD 99)
# CLI
# set(CMAKE_CXX_FLAGS "-lgtest_main")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
# shared
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# unit tests with googletest 
enable_testing()
# add googletest source code 
# add_subdirectory("/usr/local/include/gtest" ${CMAKE_BINARY_DIR}/gtest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# include(GoogleTest)

# source and header
set(HEADERS
    include/dummy.hpp
)
set(SOURCES
    src/dummy.cpp
)



# add library config
add_library(core ${HEADERS} ${SOURCES})


# lib resolution
target_include_directories(core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)


# build output
add_executable(${This} main.cpp)

# link library
target_link_libraries(${This} core )

# test cases lib
add_subdirectory(tests)