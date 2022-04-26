//
// Created by Hugo on 15/04/2022.
//

#include <gtest/gtest.h>
#include "../src/Integer.cpp"

class IntegerTest : public ::testing::Test {
protected :
    Integer a = Integer(1);
    Integer b = Integer(2);
    Integer c = Integer(0);
    Integer d = Integer(3);
    Integer e = Integer(-5);
};

TEST_F(IntegerTest, TestArithmetic) {
    EXPECT_EQ(3, (a+b).getValue());
    EXPECT_EQ(0, (a/b).getValue());
    EXPECT_EQ(2, (b/a).getValue());
    EXPECT_EQ(6, (b*d).getValue());
}

TEST_F(IntegerTest, TestReassignment) {
    a += b;
    EXPECT_EQ(3, a.getValue());
    b *= d;
    EXPECT_EQ(6, b.getValue());
}

TEST_F(IntegerTest, TestUnary) {
    EXPECT_EQ(-1, -a.getValue());
    EXPECT_EQ(5, -e.getValue());
}

TEST_F(IntegerTest, TestGCD){
    Integer x = Integer(0);
    Integer y = Integer(0);
    EXPECT_EQ(0, Integer::gcd(x, y).getValue());

    x.setValue(10);
    y.setValue(5);
    EXPECT_EQ(5, Integer::gcd(x, y).getValue());

    x = -x;
    EXPECT_EQ(5, Integer::gcd(x, y).getValue());
    EXPECT_EQ(5, Integer::gcd(y, x).getValue());

    y = -y;
    EXPECT_EQ(5, Integer::gcd(x, y).getValue());
}

TEST_F(IntegerTest, TestEquality) {
    EXPECT_TRUE(a==a);
    EXPECT_TRUE(a!=b);
    EXPECT_FALSE(a==b);
    Integer x = -a;
    EXPECT_FALSE(x==a);
    EXPECT_TRUE(x!=a);
}

TEST_F(IntegerTest, TestInEqualities) {
    EXPECT_TRUE(a <= a);
    EXPECT_TRUE(a >= a);
    EXPECT_FALSE(a < a);
    EXPECT_TRUE(a < b);
}

// Demonstrate some basic assertions.
TEST_F(IntegerTest, TestStringConstructor) {
    Integer i = Integer("1");
    EXPECT_EQ(1, i.getValue());
    Integer j = Integer("-1");
    EXPECT_EQ(-1, j.getValue());
}

TEST_F(IntegerTest, TestCopyConstructor) {
    Integer x = Integer(a);
    EXPECT_EQ(1, x.getValue());

    Integer y = Integer(e);
    EXPECT_EQ(-5, y.getValue());
}