//
// Created by Hugo on 14/04/2022.
//

#include "Integer.h"
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>

#include <bits/stdc++.h>

/**
 * For reversing strings: https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
 */

/*
 * Some Sources that we can use:
 *
 * Division:
 * https://www.geeksforgeeks.org/divide-large-number-represented-string/?fbclid=IwAR0nBCvBETTIQANRESw_YhBY9eQqThO-NE8Vu53xFQg5r_8Tfma8_hyRKY0
 *
 * Addition:
 * https://www.geeksforgeeks.org/sum-two-large-numbers/
 *
 * Subtraction:
 * https://www.gee  ksforgeeks.org/difference-of-two-large-numbers/ this finds difference, we can just switch sign
 *
 * Multiplication:
 * https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
 */


namespace cosc326 {

    Integer::Integer() = default;

    Integer::~Integer() = default;

    Integer::Integer(const std::string &digits) {
        value = parseValue(digits);
    }

    Integer::Integer(const Integer &b) {
        value = b.getValue();
    }

    std::string Integer::getValue() const {
        return value;
    }

    std::string Integer::repr() const {
        return value; // FIXME
    }

    void Integer::setValue(std::string val) {
        value = parseValue(std::move(val)); // FIXME
    }

    Integer Integer::divPositiveIntegers(const Integer &lhs, const Integer &rhs) {
        // FIXME
        std::string ans;
        std::string number = lhs.getValue();
        unsigned long long divisor = std::stoull(rhs.getValue());
        int idx = 0;
        unsigned long long temp = number[idx] - '0';
        while (temp < divisor) {
            temp = temp * 10 + (number[++idx] - '0');
        }
        while (number.size() > idx) {
            ans += std::to_string((temp / divisor) + '0');
            temp = (temp % divisor) * 10 + number[++idx] - '0';
        }
        if (ans.length() == 0) {
            return Integer("0");
        }
        return Integer(ans);
    }

    Integer operator/(const Integer &lhs, const Integer &rhs) {
        if (lhs.isPositive() && rhs.isPositive()) {
            return Integer::divPositiveIntegers(lhs, rhs);
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return -Integer::divPositiveIntegers(lhs, rhs.absValue());
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -Integer::divPositiveIntegers(lhs.absValue(), rhs);
        }
        return Integer::divPositiveIntegers(lhs.absValue(), rhs.absValue());
    }

    Integer operator+(const Integer &lhs, const Integer &rhs) {
        if (lhs.isPositive() && rhs.isPositive()) {
            return cosc326::Integer::addPositiveIntegers(lhs, rhs);
        } else if (!lhs.isPositive() && !rhs.isPositive()) {
            return -cosc326::Integer::addPositiveIntegers(+lhs, +rhs);
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return rhs.absValue() - lhs.absValue();
        }
        return lhs.absValue() - rhs.absValue();
    }

    /**
     * Multiplies two Positive Integers together
     *
     * Fails if lhs and rhs are not both positive Integers
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return a new Integer object
     */
    Integer Integer::mulPositiveIntegers(const Integer &lhs, const Integer &rhs) {
        assert(lhs.isPositive() && lhs.isPositive());

        std::string num1 = lhs.getValue();
        std::string num2 = rhs.getValue();

        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0)
            return Integer("0");

        // will keep the result number in vector
        // in reverse order
        std::vector<int> result(len1 + len2, 0);

        // Below two indexes are used to find positions
        // in result.
        int i_n1 = 0;
        int i_n2 = 0;

        // Go from right to left in num1
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = num1[i] - '0';

            // To shift position to left after every
            // multiplication of a digit in num2
            i_n2 = 0;

            // Go from right to left in num2
            for (int j = len2 - 1; j >= 0; j--) {
                // Take current digit of second number
                int n2 = num2[j] - '0';

                // Multiply with current digit of first number
                // and add result to previously stored result
                // at current position.
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

                // Carry for next iteration
                carry = sum / 10;

                // Store result
                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }

            // store carry in next cell
            if (carry > 0)
                result[i_n1 + i_n2] += carry;

            // To shift position to left after every
            // multiplication of a digit in num1.
            i_n1++;
        }

        // ignore '0's from the right
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;

        // If all were '0's - means either both or
        // one of num1 or num2 were '0'
        if (i == -1)
            return Integer("0");

        // generate the result string
        std::string s = "";

        while (i >= 0)
            s += std::to_string(result[i--]);
        return Integer(s);
    }

    Integer Integer::addPositiveIntegers(const Integer &lhs, const Integer &rhs) {
        // TODO Handle negatives
        std::string str1 = lhs.getValue();
        std::string str2 = rhs.getValue();
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length())
            swap(str1, str2);

        // Take an empty string for storing result
        std::string result = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();

        // Reverse both of strings
        reverse(str1.begin(), str1.end()); // FIXME
        reverse(str2.begin(), str2.end());

        int carry = 0;
        for (int i = 0; i < n1; i++) {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
            result.push_back(sum % 10 + '0');

            // Calculate carry for next step
            carry = sum / 10;
        }

        // Add remaining digits of larger number
        for (int i = n1; i < n2; i++) {
            int sum = ((str2[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry)
            result.push_back(carry + '0');

        // reverse resultant string
        reverse(result.begin(), result.end());

        return Integer(result);
    }

    /**
     * Finds the difference between two (positive) integers.
     *
     * Fails if lhs and rhs aren't both positive.
     *
     * Ie computes |lhs-rhs|
     *
     * @param lhs
     * @param rhs
     * @return
     */
    Integer Integer::diff(const Integer &lhs, const Integer &rhs) {
        assert(lhs.isPositive() && rhs.isPositive());
        std::string str1 = lhs.absValue().getValue();
        std::string str2 = rhs.absValue().getValue();
        // TODO normalise!
        // Before proceeding further, make sure length
        // of str2 is larger.

        // Before proceeding further, make sure str1
        // is not smaller
        if (Integer(str1) < Integer(str2)) {
            swap(str1, str2);
        }

        // Take an empty string for storing result
        std::string str = "";

        // Calculate lengths of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n2 - 1; i >= 0; i--) {
            // Do school mathematics, compute difference of
            // current digits and carry
            int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                       - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            str.push_back(sub + '0');
        }

        // subtract remaining digits of str1[]
        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1[i] == '0' && carry) {
                str.push_back('9');
                continue;
            }
            int sub = ((str1[i] - '0') - carry);
            if (i > 0 || sub > 0) // remove preceding 0's
                str.push_back(sub + '0');
            carry = 0;
        }

        // reverse resultant string
        reverse(str.begin(), str.end());

        return Integer(str);
    }

    /**
     * Subtraction operator
     *
     * @param lhs
     * @param rhs
     * @return
     */
    Integer operator-(const Integer &lhs, const Integer &rhs) {
        if (!lhs.isPositive() && !rhs.isPositive()) {
            return -(lhs.absValue() - rhs.absValue());
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -(lhs.absValue() + rhs.absValue());
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return lhs + rhs.absValue();
        } else {
            if (lhs >= rhs) {
                return Integer::diff(lhs, rhs);
            } else {
                return -Integer::diff(lhs, rhs);
            }
        }

    }

    Integer operator*(const Integer &lhs, const Integer &rhs) {
        if (lhs.isPositive() && rhs.isPositive()) {
            return Integer::mulPositiveIntegers(lhs, rhs);
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return -Integer::mulPositiveIntegers(lhs, rhs.absValue());
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -Integer::mulPositiveIntegers(lhs.absValue(), rhs);
        }
        return Integer::mulPositiveIntegers(lhs.absValue(), rhs.absValue());
    }

    Integer operator%(const Integer &lhs, const Integer &rhs) {
        return lhs;
    }


    std::ostream &operator<<(std::ostream &os, const Integer &i) {
        os << i.getValue() << std::endl;
        return os;
    }

    std::istream &operator>>(std::istream &input, Integer &b) {

        //    input >> b.getValue();
        return input;
    }

    Integer &Integer::operator=(const Integer &i) {
        this->setValue(i.getValue());
        return *this;
    }

    Integer &Integer::operator/=(const Integer &i) {
        return *this;
    }

    Integer &Integer::operator%=(const Integer &i) {
        return *this;
    }

    Integer &Integer::operator*=(const Integer &i) {
        return *this;
    }

    Integer &Integer::operator-=(const Integer &i) {
        return *this;
    }

    Integer &Integer::operator+=(const Integer &i) {
        return *this;
    }


    bool operator<(const Integer &lhs, const Integer &rhs) {
        if (lhs == rhs) {
            return false;
        }
        if (lhs.isPositive() && rhs.isPositive()) {
            return Integer::comparePositiveIntegers(lhs, rhs);
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return false;
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return true;
        }
        return !Integer::comparePositiveIntegers(lhs.absValue(), rhs.absValue());
    }

    bool operator>(const Integer &lhs, const Integer &rhs) {
        return !(lhs <= rhs);
    }

    bool operator<=(const Integer &lhs, const Integer &rhs) {
        return (lhs < rhs) || (lhs == rhs);
    }

    bool operator>=(const Integer &lhs, const Integer &rhs) {
        return (lhs > rhs) || (lhs == rhs);
    }

    bool operator==(const Integer &lhs, const Integer &rhs) {
        return lhs.getValue() == rhs.getValue();
    }

    bool operator!=(const Integer &lhs, const Integer &rhs) {
        return !(lhs == rhs);
    }

    Integer Integer::operator+() const {
        return Integer(value);
    }

    Integer Integer::operator-() const {
        if (isPositive()) {
            return Integer("-" + value);
        }
        return Integer(absValue().getValue());
    }

    /**
     * Finds out if an Integer is positive or not
     *
     * A positive number is defined as being greater than or equal to zero. A negative number is anything less than 0.
     *
     * @return bool
     */
    bool Integer::isPositive() const {
        return Integer::strIsPositive(value);
    }

    /**
     * Parses an inputted string value for the value of an Integer
     *
     * Asserts that the inputted value can be interpreted as an integer in the first place
     *
     * Tries to account for edge cases that may mess things up. Eg -0 etc
     *
     * @param value string for a integer value inputted by a user
     * @return value parsed into a usable form
     */
    std::string Integer::parseValue(std::string value) {
        // TODO handle - 0 cases
        assert(strIsInteger(value));
        value = stripPositiveSign(value);
        value = stripLeadingZeros(value);
        if (strAbsValue(value) == "0"){
            value = "0";
        }
        return value;
    }

    /**
     * Finds the absolute value of an string that can presumably be interpreted as a string
     *
     * @return string for inputted string in it's absolute value form
     */
    std::string Integer::strAbsValue(std::string str) const {
        if (!strIsPositive(str)) {
            value.substr(1);
        }
        return str;
    }

   /**
    * Finds the absolute value of this Integer
    *
    * @return a new Integer object
    */
    Integer Integer::absValue() const {
        return Integer(strAbsValue(value));
    }

    /**
     * Finds out if a string is positive.
     *
     * Assumes that the inputted string can be interpreted as a string or not
     *
     * Any str that doesn't have a leading minus sign is treated as positive.
     *
     * @param str string
     * @return
     */
    bool Integer::strIsPositive(std::string str) {
        // TODO redo with zero
        if (!str.empty()) {
            return str[0] != '-';
        }
        return false;
    }

    /**
     * Checks if a string is an integer or not
     *
     * @param str string inputted by a user
     * @return bool as described
     */
    bool Integer::strIsInteger(std::string str) {
        int i = 0;
        if (str[0] == '+' || str[0] == '-') {
            i++;
        }
        while (i < str.size()) {
            if (!('0' <= str[i] && str[i] <= '9')) {
                return false;
            }
            i++;
        }
        return true;
    }

    /**
     * Strips leading zeros from an inputted string.
     *
     * Accounts for cases where str has negative sign in front
     *
     * @param str string inputted by a user
     * @return string
     */
    std::string Integer::stripLeadingZeros(std::string str) {
        if (!Integer::strIsPositive(str)) {
            if (str.size() > 1) {
                int i = 1;
                while (str[i] == '0' && i < str.size() - 1) {
                    i++;
                }
                return str.substr(0, 1) + str.substr(i);
            } else {
                return str;
            }
        } else {
            int i = 0;
            while (str[i] == '0' && i < str.size() - 1) {
                i++;
            }
            return str.substr(i);
        }
    }

    std::string Integer::stripPositiveSign(std::string str) {
        if (str[0] == '+') {
            if (str.size() == 1) {
                return "";
            } else {
                return str.substr(1);
            }
        }
        return str;
    }

    /**
     * Compares two positive Integers to see which one is bigger
     *
     * True if lhs < rhs
     *
     * Asserts that both lhs and rhs are positive
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return bool as described
     */
    bool Integer::comparePositiveIntegers(const Integer &lhs, const Integer &rhs) {
        assert(lhs.isPositive() && rhs.isPositive());
        std::string str1 = lhs.getValue();
        std::string str2 = rhs.getValue();
        // Calculate lengths of both string
        int n1 = str1.length(), n2 = str2.length();

        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++) {
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;
        }
        return false;
    }

    /**
     * Finds the greatest common divisor between two integers.
     *
     * @param a
     * @param b
     * @return
     */
    Integer gcd(const Integer& a, const Integer &b) {
        Integer a1 = a.absValue();
        Integer b1 = b.absValue();
        if (a1 == ZERO) {
            return b1;
        } else if (b1 == ZERO) {
            return a1;
        }
        Integer remainder = a1 % b1;
        return gcd(b1, remainder);
    }
}

