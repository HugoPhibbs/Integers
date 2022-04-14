//
// Created by Hugo on 15/04/2022.
//

#include <gtest/gtest.h>
#include "../src/Integer.cpp"

// Demonstrate some basic assertions.
TEST(ConstructorTests, TestStringConstructor) {
    Integer b = Integer("1");
    EXPECT_EQ(1, b.getValue());
    Integer a = Integer("-1");
    EXPECT_EQ(-1, a.getValue());
}
// TODO
