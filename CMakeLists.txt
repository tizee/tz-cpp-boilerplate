# CMake config
cmake_minimum_required(VERSION 3.16)

set(This demo)
project(${This} VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
# specify the C standard
set(CMAKE_C_STANDARD 99)
# CLI
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
# shared
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# unit tests with googletest 
enable_testing()
add_subdirectory(googletest)

# source and header
set(HEADERS
    include/dummy.hpp
)
set(SOURCES
    src/dummy.cpp
)

# add library config
add_library(demo_core 
STATIC ${HEADERS} ${SOURCES}
)

# lib resolution
target_include_directories(demo_core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)


# build output
add_executable(${This} main.cpp)

# link library
target_link_libraries(${This} demo_core)

# test cases lib
add_subdirectory(tests)