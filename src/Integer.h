//
// Created by Hugo on 14/04/2022.
//

#include <string>
#include <ostream>
#include <iostream>

#ifndef INTEGERS_INTEGER_H
#define INTEGERS_INTEGER_H



#include <iostream>
#include <string>

namespace cosc326 {
/**
 * Class to represent an Integer
 */
    class Integer {

    private:
        /**
         * The primitive int value of this Integer
         */
        int value = 0;

    public:
        /**
         * Default constructor for an Integer
         */
        Integer();

        /**
         * Deconstructor for an Integer
         */
        ~Integer();

        /**
         * Copy constructor
         *
         * @param b Integer object to be copied
         */
        Integer(const Integer &b);

        /**
         * Constructor for an Integer
         *
         * @param digits string for digits of an integer value
         */
        explicit Integer(const std::string &digits);

        /**
         * Constructor for an Integer
         *
         * @param val int value to be set as the value of this Integer
         */
        explicit Integer(int val);

        /**
         * Finds the greatest common divisor (gcd) of two Integers a and b
         *
         * Uses the Euclidean algorithm
         *
         * @param a Integer as described
         * @param b Integer as described
         * @return Integer object as described
         */
        static Integer gcd(Integer a, Integer b);

        /**
         * The unary + operator
         *
         * @return a new Integer object
         */
        Integer operator+() const;

        /**
         * The unary - operator
         *
         * @return a new Integer object
         */
        Integer operator-() const;

        /**
         * The binary + operator
         *
         * @param b Integer object to be added to this object
         * @return a new Integer
         */
        Integer operator+(const Integer &b) const;

        /**
         * The * operator
         *
         * @param b Integer object to multiply this object
         * @return a new Integer
         */
        Integer operator*(const Integer &b) const;

        /**
         * The binary - operator. Finds this a-b where a is this Integer
         *
         * @param b Integer object
         * @return a new Integer
         */
        Integer operator-(const Integer &b) const;

        /**
         * The / operator. Finds this a/b where a is this Integer
         *
         * @param b Integer object
         * @return a new Integer
         */
        Integer operator/(const Integer &b) const;

        /**
         * The % operator. Finds this a%b where a is this Integer
         *
         * @param b Integer object
         * @return a new Integer
         */
        Integer operator%(const Integer &b) const;

        /**
         * The += operator. Finds this a+=b where a is this Integer
         *
         * @param b Integer object
         * @return this integer with b's value added
         */
        Integer operator+=(const Integer &b);

        /**
         * The *= operator. Finds this a*=b where a is this Integer
         *
         * @param b Integer object
         * @return this Integer with b's value multiplied
         */
        Integer operator*=(const Integer &b);

        /**
         * The -= operator. Finds this a-=b where a is the value of this Integer
         *
         * @param b Integer object
         * @return this Integer with b's value subtracted
         */
        Integer operator-=(const Integer &b);

        /**
         * The /= operator. Finds this a/=b where a is this Integer
         *
         * @param b Integer object
         * @return this Integer with b's value divided
         */
        Integer operator/=(const Integer &b);

        /**
         * The %= operator. Finds this a%=b where a is this Integer
         *
         * @param b Integer object
         * @return this integer with b's value mod this value
         */
        Integer operator%=(const Integer &b);

        /**
         * The == operator. Finds this a==b where a is this Integer
         *
         * @param b Integer object
         * @return bool as described
         */
        bool operator==(const Integer &b) const;

        /**
         * The != operator. Finds this a!=b where a is this Integer
         *
         * @param b Integer object
         * @return bool as described
         */
        bool operator!=(const Integer &b) const;

        /**
         * The <= operator. Finds this a<=b where a is this Integer
         *
         * @param b Integer object
         * @return bool as described
         */
        bool operator<=(const Integer &b) const;

        /**
         * The >= operator. Finds this a>=b where a is this Integer
         *
         * @param b Integer object
         * @return bool as described
         */
        bool operator>=(const Integer &b) const;

        /**
         * The < operator. Finds this a<b where a is this Integer
         *
         * @param b Integer object
         * @return bool as described
         */
        bool operator<(const Integer &b) const;

        /**
         * The > operator. Finds this a>b where a is this Integer
         *
         * @param b Integer object
         * @return bool as described
         */
        bool operator>(const Integer &b) const;

        /**
         * The << operator
         *
         * @param output std::ostream output object
         * @param b Integer object
         * @return std::ostream object
         */
        friend std::ostream &operator<<(std::ostream &output, Integer &b);

        /**
         * The >> operator
         *
         * @param output std::istream output object
         * @param b Integer object
         * @return std::istream object
         */
        friend std::istream &operator>>(std::istream &input, Integer &b);

        /**
         * The primitive int value of this Integer
         *
         * @return int as described
         */
        int getValue() const;

        /**
         * Sets the value of this Integer
         *
         * @param val int for value to be set
         */
        void setValue(int val);

        /**
         * Assignment operator
         *
         * @param i Integer to be assigned to this integer
         * @return this Integer
         */
        Integer& operator=(const Integer& i);

        /**
         * Returns a string representation of this Integer
         * @return string as described
         */
        std::string repr() const;
    };
}
#endif //INTEGERS_INTEGER_H