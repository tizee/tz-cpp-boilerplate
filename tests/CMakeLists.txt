cmake_minimum_required(VERSION 3.16)

# add test cases
set(SOURCES
    DummyTest.cpp
)

# build tests
add_executable(demo_test ${SOURCES})
# add linker flags for compiled googletest libs
set(CMAKE_LINK_LIBRARY_FLAG "-lgtest -lgtest_main")

# link libs
target_link_libraries(demo_test
    # if build from source then use gtest_main from googletest config 
    # compiled gtest libs
    "/usr/local/lib/libgtest.a"
    "/usr/local/lib/libgtest_main.a"
    core
)

# add to ctest
add_test(
    NAME demo_test
    COMMAND demo_test
)