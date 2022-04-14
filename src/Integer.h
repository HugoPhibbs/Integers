//
// Created by Hugo on 14/04/2022.
//

#include <string>

#ifndef INTEGERS_INTEGER_H
#define INTEGERS_INTEGER_H

#endif //INTEGERS_INTEGER_H

/**
 * Class to represent an Integer
 */
class Integer {

private:
    /**
     * The primitive int value of this Integer
     */
    int value;


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
     * Constructor for an Integer, copies another integer
     *
     * @param i Integer object to be copied
     */
    Integer(Integer i);

    /**
     * Constructor for an Integer
     *
     * @param digits string for digits of an integer value
     */
    Integer(std::string digits);

    /**
     * Finds the greatest common divisor (gcd) of two Integers a and b
     *
     * @param a Integer as described
     * @param b Integer as described
     * @return Integer object as described
     */
    static Integer gcd(Integer a, Integer b);

    /**
     * The + operator
     *
     * @param b Integer object to be added to this object
     * @return a new Integer
     */
    Integer operator+(const Integer& b);

    /**
     * The * operator
     *
     * @param b Integer object to multiply this object
     * @return a new Integer
     */
    Integer operator*(const Integer& b);

    /**
     * The - operator. Finds this a-b where a is this Integer
     *
     * @param b Integer object
     * @return a new Integer
     */
    Integer operator-(const Integer& b);

    /**
     * The / operator. Finds this a/b where a is this Integer
     *
     * @param b Integer object
     * @return a new Integer
     */
    Integer operator/(const Integer& b);

    /**
     * The % operator. Finds this a%b where a is this Integer
     *
     * @param b Integer object
     * @return a new Integer
     */
    Integer operator%(const Integer& b);

    /**
     * The += operator. Finds this a+=b where a is this Integer
     *
     * @param b Integer object
     * @return this integer with b's value added
     */
    Integer operator+=(const Integer& b);

    /**
     * The *= operator. Finds this a*=b where a is this Integer
     *
     * @param b Integer object
     * @return this integer with b's value multiplied
     */
    Integer operator*=(const Integer& b);

    /**
     * The -= operator. Finds this a-=b where a is the value of this Integer
     *
     * @param b Integer object
     * @return this integer with b's value subtracted
     */
    Integer operator-=(const Integer& b);

    /**
     * The /= operator. Finds this a/=b where a is this Integer
     *
     * @param b Integer object
     * @return this integer with b's value divided
     */
    Integer operator/=(const Integer& b);

    /**
     * The %= operator. Finds this a%=b where a is this Integer
     *
     * @param b Integer object
     * @return this integer with b's value mod this value
     */
    Integer operator%=(const Integer& b);

    /**
     * The == operator. Finds this a==b where a is this Integer
     *
     * @param b Integer object
     * @return bool as described
     */
    bool operator==(const Integer& b);

    /**
     * The != operator. Finds this a!=b where a is this Integer
     *
     * @param b Integer object
     * @return bool as described
     */
    bool operator!=(const Integer& b);

    /**
     * The <= operator. Finds this a<=b where a is this Integer
     *
     * @param b Integer object
     * @return bool as described
     */
    bool operator<=(const Integer& b);

    /**
     * The >= operator. Finds this a>=b where a is this Integer
     *
     * @param b Integer object
     * @return bool as described
     */
    bool operator>=(const Integer& b);

    /**
     * The < operator. Finds this a<b where a is this Integer
     *
     * @param b Integer object
     * @return bool as described
     */
    bool operator<(const Integer& b);

    /**
     * The > operator. Finds this a>b where a is this Integer
     *
     * @param b Integer object
     * @return bool as described
     */
    bool operator>(const Integer& b);

    Integer operator<<(const Integer& b);

    Integer operator>>(const Integer& b);


    /**
     * The primitive int value of this Integer
     *
     * @return int as described
     */
    int getValue() const;

};