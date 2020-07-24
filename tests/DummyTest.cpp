#include <gtest/gtest.h>
#include <iostream>
#include "../include/dummy.hpp"

// fixture(test setup)
// see interface in testing::Test
struct DummyTest : public ::testing::Test
{
    virtual void SetUp() override
    {
        std::cout << "Start Test" << std::endl;
    }
    virtual void TearDown() override
    {
        std::cout << "Test End" << std::endl;
    }
};

// could use --gtest_filter to choose test suit
TEST_F(DummyTest, SayHi)
{
    std::cout << "Go 😆" << std::endl;
    EXPECT_EQ(dummy::hello(), "👋 Hi~");
};
TEST(DummyTest2, SayHi)
{
    std::cout << "Go 😆" << std::endl;
    EXPECT_EQ(dummy::hello(), "👋 Hi~ !!");
};