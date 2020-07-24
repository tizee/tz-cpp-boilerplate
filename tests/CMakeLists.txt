cmake_minimum_required(VERSION 3.16)

# add test cases
set(SOURCES
    DummyTest.cpp
)

# build tests
add_executable(demo_test ${SOURCES})


# link libs
target_link_libraries(demo_test PUBLIC
    # googletest entry
    gtest_main
    demo_core
)

# add to ctest
add_test(
    NAME demo_test
    COMMAND demo_test
)