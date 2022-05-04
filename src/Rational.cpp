//
// Created by Hugo on 14/04/2022.
//

#include <string>
#include <ostream>
#include <iostream>
#include "Rational.h"
#include <vector>

namespace cosc326 {

    Rational::Rational() {
        whole = Integer();
        num = Integer();
        den = Integer(1);
    }

    Rational::Rational(const std::string &str) {
        std::vector<std::string> hold;

        std::vector<std::string> words;
        std::string s;
        std::string separator = ",";

    }

    Rational::Rational(const Rational &r) {
        this->den = r.den;
        this->num = r.num;
    }

    Rational::Rational(const Integer &a) {
        this->num = a;
        this->den = Integer(1);
    }

    Rational::Rational(const Integer &a, const Integer &b) {
        this->num = a;
        this->den = b;
    }

    Rational::Rational(const Integer &a, const Integer &b, const Integer &c) {

    }

    Rational::~Rational() {

    }

    Rational &Rational::operator=(const Rational &r) {
        Rational a = r.convertToImprop();
        this->num = r.num;
        this->den = r.den;
        return *this;
    }

    Rational Rational::operator-() const { //need more help??
        return Rational(-getValue());
    }

    Rational Rational::operator+() const {
        return Rational(+getValue());
    }

    Rational &Rational::operator+=(const Rational &r) {
        Rational a = r.convertToImprop();
        *this = Rational(*this+r);
        return *this;
    }


    Rational &Rational::operator-=(const Rational &r) {
        Rational a = r.convertToImprop();
        *this = Rational(*this-r);
        return *this;
        //implement simplfy

    }

    Rational &Rational::operator*=(const Rational &r) {
        Rational a = r.convertToImprop();
        *this = Rational(*this*r);

        return *this;
    }

    Rational &Rational::operator/=(const Rational &r) { //need to ask for help on this
        Rational a = r.convertToImprop();
        *this = Rational(*this/r);
        return *this;
    }

    Rational operator+(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        Rational temp;
        Integer tempNum = (rhs.num * lhs.den) + (rhs.den *lhs.num);
        Integer tempDen = rhs.den * lhs.den;
        temp.num = tempNum;
        temp.den = tempDen;
        // to be implemented simplify(temp)
        return temp;
    }

    Rational operator-(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        Rational temp;
        temp.num = (lhs.num * rhs.den) - (rhs.num * lhs.den);
        temp.den = lhs.den * rhs.den;
        return temp;
    }

    Rational operator*(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        Rational temp;
        temp = temp.convertToImprop();
        temp.num = lhs.num * rhs.num;
        temp.den = lhs.den * rhs.den;
        //simplify to he implemented
        return temp;
    }

    Rational operator/(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        Rational temp;
        temp.num = lhs.num * rhs.den;
        temp.den = lhs.den * rhs.num;
        return temp;

    }

    std::ostream &operator<<(std::ostream &os, const Rational &i) {
        Rational temp = i.convertToImprop();
        os << temp.num << '/' << temp.den;
        return os;
    }

    std::istream &operator>>(std::istream &is, Rational &i) {
        is >> i.den >> i.num;
        return is;
    }

    bool operator<(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 < temp2) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 > temp2) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<=(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        if ((lhs < rhs) || (lhs == rhs)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>=(const Rational &lhs, const Rational &rhs) { //look into this???
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        if ((lhs > rhs) || (lhs == rhs)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        if (lhs / rhs == Rational(0)) {
            return true;
        } else {
            return true;
        }
    }

    bool operator!=(const Rational &lhs, const Rational &rhs) {
        Rational a = lhs.convertToImprop();
        Rational b = rhs.convertToImprop();
        if ((lhs.simplify() / rhs.simplify()) != Rational(0)) {
            return true;
        } else {
            return true;
        }
    }



    Rational Rational::simplify() const { //what am i doing wrong?????
        Rational temp;/**
        Integer gcd;
        gcd = Integer(gcd.gcd(this->den, this->num));
        temp.den = den/gcd;
        temp.num = num/gcd;
        if(temp.num <= temp.den){
            if(temp.num == temp.den) {
                temp.whole += Integer(1);
                temp.den = Integer(0);
                temp.num = Integer(0);
            } else {


            }


        }
         */
        return *this;

    }
    Rational Rational::getValue() const {
        Rational temp;
        temp.den = this->den;
        temp.num = this->num;
        return temp;
    }

    Rational Rational::convertToImprop() const {
        if (this->whole == Integer(0)){
            return *this;
        } else {
            Rational temp;
            temp.den = this->den;
            temp.num = (this->whole * this->den) + this->num;
            temp.whole = Integer(0);
            return temp;
        }

    }
};



