//
// Created by Hugo on 14/04/2022.
//

#include "Integer.h"
#include <cstdlib>
#include <string>

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
 * https://www.geeksforgeeks.org/difference-of-two-large-numbers/ this finds difference, we can just switch sign
 *
 * Multiplication:
 * https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
 */


namespace cosc326 {
    Integer::Integer() = default;

    Integer::~Integer() = default;

    Integer::Integer(const std::string &digits) {
        value = digits;
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

    Integer Integer::absValue() const {
        return Integer(); // FIXME
    }

    void Integer::setValue(std::string val) {
        value = val; // FIXME
    }

    Integer operator/(const Integer &lhs, const Integer &rhs) {
        std::string ans;
        std::string number = lhs.getValue();
        unsigned long long divisor = strtoull(rhs.getValue().c_str(), nullptr, 10);
        int idx = 0;
        unsigned long long temp = number[idx] - '0';
        while (temp < divisor) {
            temp = temp * 10 + (number[++idx] - '0');
        }
        while (number.size() > idx) {
            ans += std::to_string((temp / divisor) + '0');
            temp = (temp % divisor) * 10 + number[++idx] - '0';
        }
        if (ans.length() == 0)
            return Integer("0");
        return Integer(ans);
    }

    Integer operator+(const Integer& lhs, const Integer& rhs) {
        std::string str1 = lhs.getValue();
        std::string str2 = rhs.getValue();
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length())
            swap(str1, str2);

        // Take an empty string for storing result
        std:: string result = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();

        // Reverse both of strings
        reverse(str1.begin(), str1.end()); // FIXME
        reverse(str2.begin(), str2.end());

        int carry = 0;
        for (int i=0; i<n1; i++)
        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            result.push_back(sum % 10 + '0');

            // Calculate carry for next step
            carry = sum/10;
        }

        // Add remaining digits of larger number
        for (int i=n1; i<n2; i++)
        {
            int sum = ((str2[i]-'0')+carry);
            result.push_back(sum % 10 + '0');
            carry = sum/10;
        }

        // Add remaining carry
        if (carry)
            result.push_back(carry + '0');

        // reverse resultant string
        reverse(result.begin(), result.end());

        return Integer(result);
    }

    Integer operator-(const Integer& lhs, const Integer& rhs) {
        std::string str1 = lhs.getValue();
        std::string str2 = rhs.getValue();
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length())
            swap(str1, str2);

        // Take an empty string for storing result
        std:: string result = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();

        // Reverse both of strings
        reverse(str1.begin(), str1.end()); // FIXME
        reverse(str2.begin(), str2.end());

        int carry = 0;
        for (int i=0; i<n1; i++)
        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i]-'0')- (str2[i]-'0')+carry);
            result.push_back(sum % 10 + '0');

            // Calculate carry for next step
            carry = sum/10;
        }

        // Add remaining digits of larger number
        for (int i=n1; i<n2; i++)
        {
            int sum = ((str2[i]-'0')+carry);
            result.push_back(sum % 10 + '0');
            carry = sum/10;
        }

        // Add remaining carry
        if (carry)
            result.push_back(carry + '0');

        // reverse resultant string
        reverse(result.begin(), result.end());

        return Integer(result);
    }

    Integer operator*(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator%(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }


    std::ostream &operator<<(std::ostream &output, Integer &b) {
        output << b.getValue() << std::endl;
        return output;
    }

    std::istream &operator>>(std::istream &input, Integer &b) {

    //    input >> b.getValue();
        return input;
    }

    Integer& Integer::operator=(const Integer& i) {
        this->setValue(i.getValue());
        return *this;
    }

    Integer &Integer::operator/=(const Integer &i) {
        return <#initializer#>;
    }

    Integer &Integer::operator%=(const Integer &i) {
        return <#initializer#>;
    }

    Integer &Integer::operator*=(const Integer &i) {
        return <#initializer#>;
    }

    Integer &Integer::operator-=(const Integer &i) {
        return <#initializer#>;
    }

    Integer &Integer::operator+=(const Integer &i) {
        return <#initializer#>;
    }

    bool operator<(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator> (const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator<=(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator>=(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator==(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator!=(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    Integer Integer::operator+() const {
        return Integer();
    }

    Integer Integer::operator-() const {
        return Integer();
    }

    bool Integer::isPositive() const {
        return strcmp(value.at(0), &"0"); // FIXME
    }



    Integer gcd(const Integer& a, const Integer& b) {
        return a;
    }

}

