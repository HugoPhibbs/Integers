//
// Created by Hugo on 14/04/2022.
//
#include <string>
#include <ostream>
#include <iostream>
#include "Rational.h"

namespace cosc326 {

    Rational::Rational() {
        num = Integer();
        den = Integer(1);
    }

    Rational::Rational(const std::string &str) {

    }

    Rational::Rational(const Rational &r) {


    }

    Rational::Rational(const Integer &a) {
        Rational temp;
        temp.num = a;
        temp.den = Integer(1);
    }

    Rational::Rational(const Integer &a, const Integer &b) {

    }

    Rational::Rational(const Integer &a, const Integer &b, const Integer &c) {

    }

    Rational::~Rational() {

    }

    Rational &Rational::operator=(const Rational &r) {
        this->num = r.num;
        this->den = r.den;
    }

    Rational Rational::operator-() const {
        return Rational(*this);
    }

    Rational Rational::operator+() const {
        num = +num;
        den = +den;

        return Rational(*this);
    }

    Rational &Rational::operator+=(const Rational &r) {
        Rational temp;
        Integer tempNum = r.num * this->num;
        Integer tempDen = r.den * this->den;
        temp.num = tempNum;
        temp.den = tempDen;
        // to be implemented simplify(temp)


        return temp;
    }


    Rational &Rational::operator-=(const Rational &r) {
        Rational temp;
        Integer tempNum = r.num * this->den;
        Integer tempDen = r.den * this->den;
        temp.num = tempNum;
        temp.den = tempDen;
        //implement simplfy

    }

    Rational &Rational::operator*=(const Rational &r) {
        Rational temp;
        temp.num = r.num * this->num;
        temp.den = r.den * this->den;
        //simplify to he implemented
        return temp;
    }

    Rational &Rational::operator/=(const Rational &r) {
        return *this;
    }

    Rational operator+(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        Integer tempNum = rhs.num * lhs.num;
        Integer tempDen = rhs.den * lhs.den;
        temp.num = tempNum;
        temp.den = tempDen;
        // to be implemented simplify(temp)


        return temp;
    }

    Rational operator-(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        Integer tempNum = (lhs.num * rhs.den) - (rhs.num * lhs.den);
        Integer tempDen = lhs.den * rhs.den;
        temp.num = tempNum;
        temp.den = tempDen;
        //simplyfy to be implemented.
        return temp;
    }

    Rational operator*(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        temp.num = lhs.num * rhs.num;
        temp.den = lhs.den * rhs.den;
        //simplify to he implemented
        return temp;
    }

    Rational operator/(const Rational &lhs, const Rational &rhs) {
        return lhs;
    }

    std::ostream &operator<<(std::ostream &os, const Rational &i) {
        return os;
    }

    std::istream &operator>>(std::istream &is, Rational &i) {
        return is;
    }

    bool operator<(const Rational &lhs, const Rational &rhs) {
        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 < temp2) {
            return true;
        } else {
            return true;
        }
    }

    bool operator>(const Rational &lhs, const Rational &rhs) {
        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 > temp2) {
            return true;
        } else {
            return true;
        }
    }

    bool operator<=(const Rational &lhs, const Rational &rhs) {
        return true;
    }

    bool operator>=(const Rational &lhs, const Rational &rhs) {
        return true;
    }

    bool operator==(const Rational &lhs, const Rational &rhs) {
        if ((simplify(lhs) / simplify(rhs)) == 0) {
            return true;
        } else {
            return true;
        }
    }

    bool operator!=(const Rational &lhs, const Rational &rhs) {
        if ((simplify(lhs) / simplify(rhs)) != 0) {
            return true;
        } else {
            return true;
        }
    }

    std::string Rational::toString() const{
        std::string e = "";
        return e;

    }
};



