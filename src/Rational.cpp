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
        whole = Integer();
        Rational temp;
        std::size_t foundDot = str.find(".");
        std::size_t foundSlash = str.find("/");
        if (foundDot != std::string::npos) {
            std::string wholeS = str.substr(0, foundDot);
            std::string num = str.substr(foundDot+1, foundSlash - foundDot-1);
            std::string den = str.substr(foundSlash+1, str.length()+1);
            int numberW = stoi(wholeS);
            int numberN = stoi(num);
            int numberD = stoi(den);
            temp.whole = Integer(numberW);
            temp.num = Integer(numberN);
            temp.den = Integer(numberD);
            temp = temp.convertToImprop();
            this->den = temp.den;
            this->num = temp.num;
        } else {
                std::string num = str.substr(0, foundSlash);
                std::string den = str.substr(foundSlash+1, foundSlash-str.length()+1);
                int numberN = stoi(num);
                int numberD = stoi(den);
                this->den = Integer(numberD);
                this->num = Integer(numberN);
        }



    };

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
        Rational temp;

        temp.whole = Integer(a);
        temp.num = Integer(b);
        temp.den = Integer(c);
        temp = temp.convertToImprop();
        this->den = temp.den;
        this->num = temp.num;

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


    }

    Rational &Rational::operator*=(const Rational &r) {
        Rational a = r.convertToImprop();
        *this = Rational(*this*r);
        return *this;
    }

    Rational &Rational::operator/=(const Rational &r) {
        Rational a = r.convertToImprop();
        *this = Rational(*this/r);
        return *this;
    }

    Rational operator+(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        Integer tempNum = ((lhs.num * rhs.den) + (rhs.num * lhs.den));
        Integer tempDen = rhs.den * lhs.den;
        temp.num = tempNum;
        temp.den = tempDen;
        return temp.simplify();
    }

    Rational operator-(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        temp.num = (lhs.num * rhs.den) - (rhs.num * lhs.den);
        temp.den = lhs.den * rhs.den;
        return temp.simplify();
    }

    Rational operator*(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        temp = temp.convertToImprop();
        temp.num = lhs.num * rhs.num;
        temp.den = lhs.den * rhs.den;
        return temp.simplify();
    }

    Rational operator/(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        temp.den = rhs.num * lhs.den;
        temp.num = rhs.den * lhs.num;
        return temp.simplify();

    }

    std::ostream &operator<<(std::ostream &os, const Rational &i) {
        std::string s;
        Rational temp = i.toWholeForm();
        if (temp.den == temp.num) {
            s = "1";
            os << s;
        } else if(temp.num == Integer(0)){
            s = temp.whole.repr();
            os << s;
        }
        else if (temp.whole == Integer(0)) {
            s = temp.num.repr() + "/" + temp.den.repr();
            os << s;
        } else {
            std::string n = temp.num.repr();
            int nInt = stoi(n);
            temp.num = Integer(abs(nInt));
            s = temp.whole.repr() + "." + temp.num.repr()+ "/" + temp.den.repr();
            os << s;
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Rational &i) {
        is >> i.den >> i.num;
        return is;
    }

    bool operator<(const Rational &lhs, const Rational &rhs) {
        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 < temp2) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Rational &lhs, const Rational &rhs) {

        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 > temp2) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<=(const Rational &lhs, const Rational &rhs) {

        if ((lhs < rhs) || (lhs == rhs)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>=(const Rational &lhs, const Rational &rhs) { //look into this???

        if ((lhs > rhs) || (lhs == rhs)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(const Rational &lhs, const Rational &rhs) {

        if (lhs / rhs == Rational(0)) {
            return true;
        } else {
            return true;
        }
    }

    bool operator!=(const Rational &lhs, const Rational &rhs) {

        if ((lhs.simplify() / rhs.simplify()) != Rational(0)) {
            return true;
        } else {
            return true;
        }
    }
    Rational Rational::toWholeForm() const {
        std::string n = this->num.repr();
        std::string d = this->den.repr();
        int dInt = stoi(d);
        int nInt = stoi(n);
        Integer numer = (this->num);
        Integer denom = Integer(this->den);
        if(abs(nInt) > abs(dInt)) {
            Integer iwhole = this->num / this->den;
            Integer remain = this->num % this->den;
            Rational temp;
            temp.whole = iwhole;
            temp.num = remain;
            temp.den = this->den;
            return temp;
        } else {
            return *this;
        }
    }




    Rational Rational::simplify() const { //what am i doing wrong?????
        Rational temp;
        Integer gcd;
        gcd = Integer(gcd.gcd(this->den, this->num));
        temp.den = den/gcd;
        temp.num = num/gcd;
        return temp;
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
    Rational Rational::toString() const {
        return *this;
    }
};



