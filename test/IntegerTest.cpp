//
// Created by Hugo on 15/04/2022.
//

#include <gtest/gtest.h>
#include "../src/Integer.cpp"

namespace cosc326 {

    class IntegerTest : public ::testing::Test {
    protected :
        Integer a = Integer("1");
        Integer b = Integer("2");
        Integer c = Integer("0");
        Integer d = Integer("3");
        Integer e = Integer("-5");
        Integer f = Integer("-10");
        Integer g = Integer("-2");
        Integer h = Integer("7");
        Integer i = Integer("-1");
        Integer j = Integer("18");
    };

    TEST_F(IntegerTest, TestBasicArithmetic) {
        EXPECT_EQ("3", (a + b).getValue());
        EXPECT_EQ("0", (a / b).getValue());
        EXPECT_EQ("2", (b / a).getValue());
        EXPECT_EQ("6", (b * d).getValue());
    }

    TEST_F(IntegerTest, TestReassignment) {
        a += b;
        EXPECT_EQ("3", a.getValue());
        b *= d;
        EXPECT_EQ("6", b.getValue());
        f /= g;
        EXPECT_EQ("5", f.getValue());
        h -= d;
        EXPECT_EQ("4", h.getValue());
    }

    TEST_F(IntegerTest, TestUnary) {
        EXPECT_EQ("-1", (-a).getValue());
        EXPECT_EQ("5", (-e).getValue());
        EXPECT_EQ("0", (-c).getValue());
        EXPECT_EQ("-1", (+i).getValue());
        EXPECT_EQ("1", (-i).getValue());
    }

    TEST_F(IntegerTest, TestGCD) {
        Integer x = Integer("0");
        Integer y = Integer("0");
        EXPECT_EQ("0", gcd(x, y).getValue());

        x.setValue("10");
        y.setValue("5");
        EXPECT_EQ("5", gcd(x, y).getValue());

        x = -x;
        EXPECT_EQ("5", gcd(x, y).getValue());
        EXPECT_EQ("5", gcd(y, x).getValue());

        y = -y;
        EXPECT_EQ("5", gcd(x, y).getValue());
    }

    TEST_F(IntegerTest, TestEquality) {
        EXPECT_TRUE(a == a);
        EXPECT_TRUE(a != b);
        EXPECT_FALSE(a == b);
        Integer x = -a;
        EXPECT_FALSE(x == a);
        EXPECT_TRUE(x != a);
    }

    TEST_F(IntegerTest, TestInEqualities) {
        EXPECT_TRUE(a <= a);
        EXPECT_TRUE(a >= a);
        EXPECT_FALSE(a < a);
        EXPECT_TRUE(a < b);
        EXPECT_TRUE(b < a);
        EXPECT_TRUE(d > e);
    }

    TEST_F(IntegerTest, TestAbsValue) {
        EXPECT_EQ("1", a.absValue().getValue());
        EXPECT_EQ("10", f.absValue().getValue());
        EXPECT_EQ("0", c.absValue().getValue());
    }

    TEST_F(IntegerTest, TestSubtraction) {
        EXPECT_EQ("-8", (e - d).getValue());
        EXPECT_EQ("-5", (f - e).getValue());
        EXPECT_EQ("-3", (e - g).getValue());
        EXPECT_EQ("-1", (b - d).getValue());
        EXPECT_EQ("1", (d - b).getValue());
        EXPECT_EQ("4", (h - d).getValue());
        EXPECT_EQ("0", (d - d).getValue());
        EXPECT_EQ("0", (c - c).getValue());

        EXPECT_EQ("9999999", (Integer("10000000") - a).getValue());
    }

    TEST_F(IntegerTest, TestAddition) {
        EXPECT_EQ("5", (d + b).getValue());
        EXPECT_EQ("-15", (f + e).getValue());
        EXPECT_EQ("-3", (b + e).getValue());
        EXPECT_EQ("-3", (e + b).getValue());
        EXPECT_EQ("0", (c + c).getValue());
        EXPECT_EQ("2", (b + c).getValue());
    }

    TEST_F(IntegerTest, TestMultiplication) {
        /*
         * Test
         * multiplication by zero
         * positive positive
         * negative positive
         * postive negative
         * negative negative
         * zero negative
         * zero positive
         */
        EXPECT_EQ("0", (c * c).getValue());
        EXPECT_EQ("0", (c * e).getValue());
        EXPECT_EQ("0", (c * a).getValue());

        EXPECT_EQ("1", (a * a).getValue());
        EXPECT_EQ("-5", (a * e).getValue());
        EXPECT_EQ("-10", (f * a).getValue());
        EXPECT_EQ("3", (a * d).getValue());
        EXPECT_EQ("6", (b * d).getValue());

        EXPECT_EQ("50", (e * f).getValue());
        EXPECT_EQ("50", (f * e).getValue());
        EXPECT_EQ("-14", (g * h).getValue());
        EXPECT_EQ("-14", (h * g).getValue());
    }

    TEST_F(IntegerTest, TestDivision) {
        /*
         * Test
         * division with numerator zero
         * positive positive
         * negative positive
         * postive negative
         * negative negative
         * zero negative
         * zero positive
         */
        EXPECT_EQ("0", (c / d).getValue());
        EXPECT_EQ("0", (c / i).getValue());
        EXPECT_EQ("-7", (h / i).getValue());
        EXPECT_EQ("3", (d / a).getValue());
        EXPECT_EQ("6", (j / d).getValue());
        EXPECT_EQ("-6", (-j / d).getValue());
        EXPECT_EQ("-9", (j / g).getValue());
        EXPECT_EQ("5", (f / e).getValue());
    }

    TEST_F(IntegerTest, TestStringConstructor) {
        Integer i = Integer("1");
        EXPECT_EQ("1", i.getValue());
        Integer j = Integer("-1");
        EXPECT_EQ("-1", j.getValue());

        EXPECT_EQ("0", Integer("+0").getValue());

        EXPECT_EQ("10", Integer("+10").getValue());

        EXPECT_EQ("0", Integer("0").getValue());
        EXPECT_EQ("0", Integer("-0").getValue());
        EXPECT_EQ("0", Integer("-0000000").getValue());
        EXPECT_EQ("0", Integer("0000000").getValue());
    }

    TEST_F(IntegerTest, TestModulo) {
        // TODO
    }

    TEST_F(IntegerTest, TestCopyConstructor) {
        Integer x = Integer(a);
        EXPECT_EQ("1", x.getValue());

        Integer y = Integer(e);
        EXPECT_EQ("-1", y.getValue());
    }
}