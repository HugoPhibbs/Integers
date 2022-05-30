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

    TEST_F(IntegerTest, TestAssignment) {
        Integer x = Integer("4");
        x = g;
        EXPECT_EQ("-2", x.getValue());
        EXPECT_EQ("-2", g.getValue());
        x+=b;
        EXPECT_EQ("0", x.getValue());
        EXPECT_EQ("-2", g.getValue());
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
        h %= d;
        EXPECT_EQ("1", h.getValue());
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

        x = -x; // x now -5
        EXPECT_EQ("5", gcd(x, y).getValue());
        EXPECT_EQ("5", gcd(y, x).getValue());

        y = -y;
        EXPECT_EQ("5", gcd(x, y).getValue());

        EXPECT_EQ("4", gcd(Integer("4"), Integer("4")).getValue());
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
        EXPECT_FALSE(b < a);
        EXPECT_TRUE(d > e);
        EXPECT_TRUE(i < h);
        EXPECT_TRUE(e < i);
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

        // Big Numbers
        EXPECT_EQ("62386149467931173657937623830189851280126870913571634187803335663909242", (Integer("456787484812957596827") * Integer("136575872899575287489595712748754917457626458917646")).getValue());
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
        EXPECT_EQ("2", (f / e).getValue());

        EXPECT_EQ("25", (Integer("125") / Integer("5")).getValue());
        EXPECT_EQ("312", (Integer("1248") / Integer("4")).getValue());
        EXPECT_EQ("97", (Integer("291") / Integer("3")).getValue());

        EXPECT_EQ("2", (j / h).getValue());
        EXPECT_EQ("-2", (Integer("-15") / Integer("7")).getValue());
        EXPECT_EQ("2", (Integer("-15") / Integer("-7")).getValue());

        // Big Number tests!
        EXPECT_EQ("500", (Integer("2000") / Integer("4")).getValue());
        EXPECT_EQ("10444451", (Integer("52222255") / Integer("5")).getValue());
    }

    TEST_F(IntegerTest, TestBigNumberDivision) {
        EXPECT_EQ("500", (Integer("2000") / Integer("4")).getValue());
        EXPECT_EQ("10444451", (Integer("52222255") / Integer("5")).getValue());

        // 100!/50!
        Integer fact100 = Integer(
                "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
        Integer fact50 = Integer("30414093201713378043612608166064768844377641568960512000000000000");
        EXPECT_EQ("3068518756254966037202730459529469739228459721684688959447786986982158958772355072000000000000",
                  (fact100 / fact50).getValue());
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
        EXPECT_EQ("0", (j % d).getValue());
        EXPECT_EQ("6", (Integer("-15") % Integer("7")).getValue());
        EXPECT_EQ("6", (Integer("-15") % Integer("-7")).getValue());
        EXPECT_EQ("1", (Integer("15") % Integer("7")).getValue());
        EXPECT_EQ("0", (Integer("14") % Integer("7")).getValue());
        EXPECT_EQ("0", (c % g).getValue());
        EXPECT_EQ("0", (c % b).getValue());
        EXPECT_EQ("0", (h % h).getValue());
        EXPECT_EQ("0", (h % (-h)).getValue());
        EXPECT_EQ("0", ((-h) % (-h)).getValue());
        EXPECT_EQ("0", ((-h) % (+h)).getValue());
        EXPECT_EQ("5", (Integer("5") % Integer("10")).getValue());
    }

    TEST_F(IntegerTest, TestCopyConstructor) {
        Integer x = Integer(a);
        EXPECT_EQ("1", x.getValue());

        Integer y = Integer(i);
        EXPECT_EQ("-1", y.getValue());
        y -= a; // Check memory spot not tethered
        EXPECT_EQ("-2", y.getValue());
        EXPECT_EQ("-1", i.getValue());
    }
}