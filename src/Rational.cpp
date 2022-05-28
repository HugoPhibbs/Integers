//
// Created by Hugo on 14/04/2022.
//

#include <string>
#include <ostream>
#include "Rational.h"
#include "Integer.h"
#include <vector>

namespace cosc326 {

    Rational::Rational() {
        num = Integer();
        den = Integer("1");
    }

    Rational::Rational(const std::string &str) {
        Integer whole = Integer();
        Rational temp;
        std::size_t foundDot = str.find(".");
        std::size_t foundSlash = str.find("/");
        if (foundDot != std::string::npos) {
            std::string wholeS = str.substr(0, foundDot);
            std::string num = str.substr(foundDot + 1, foundSlash - foundDot - 1);
            std::string den = str.substr(foundSlash + 1, str.length() + 1);
            temp = convertToImproper(Integer(wholeS), Integer(num), Integer(den));
            this->den = temp.den;
            this->num = temp.num;
        } else {
            std::string num = str.substr(0, foundSlash);
            std::string den = str.substr(foundSlash + 1, foundSlash - str.length() + 1);
            this->den = Integer(num);
            this->num = Integer(den);
        }

    };

    Rational::Rational(const Rational &r) {
        this->den = r.den;
        this->num = r.num;
    }

    Rational::Rational(const Integer &a) {
        this->num = a;
        this->den = Integer("1");
    }

    Rational::Rational(const Integer &a, const Integer &b) {
        this->num = a;
        this->den = b;
    }

    Rational::Rational(const Integer &a, const Integer &b, const Integer &c) {
        Rational g = convertToImproper(a, b, c);
        this->den = g.den;
        this->num = g.num;

    }

    Rational::~Rational() = default;

    Rational &Rational::operator=(const Rational &r) {
        //  Rational a = r.convertToImprop();
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
        //  Rational a = r.convertToImprop();
        *this = Rational(*this + r);
        return *this;
    }


    Rational &Rational::operator-=(const Rational &r) {
        //  Rational a = r.convertToImprop();
        *this = Rational(*this - r);
        return *this;


    }

    Rational &Rational::operator*=(const Rational &r) {
        //  Rational a = r.convertToImprop();
        *this = Rational(*this * r);
        return *this;
    }

    Rational &Rational::operator/=(const Rational &r) {
        // Rational a = r.convertToImprop();
        *this = Rational(*this / r);
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
        temp.num = lhs.num * rhs.num;
        temp.den = lhs.den * rhs.den;
        return temp.simplify();
    }

    Rational operator/(const Rational &lhs, const Rational &rhs) {
        Rational temp;
        temp.num = lhs.num * rhs.den;
        temp.den = lhs.den * rhs.num;
        return temp.simplify();

    }

    std::ostream &operator<<(std::ostream &os, const Rational &i) {
        std::string s;
        Integer whole, numerator, denomnator;
        int x = stoi(i.num.repr());
        int g = stoi(i.den.repr());
        if (abs(x) > abs(g)) {
            whole = i.num / i.den;
            int p = abs(stoi(i.num.repr()) % stoi(i.den.repr()));
            numerator = Integer(p);
            denomnator = Integer(abs(stoi(i.den.repr())));
            s = whole.repr() + "." + numerator.repr() + "/" + denomnator.repr();
            os << s;
        } else if (abs(stoi(i.num.repr())) == abs(stoi(i.den.repr()))) {
            os << "1";
        } else {
            s = i.num.repr() + "/" + i.den.repr();
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
        Rational temp = lhs / rhs;
        if ((abs(stoi(temp.num.repr()))) == 1 && (abs(stoi(temp.den.repr())) == 1)) {
            return true;
        } else {
            return false;
        }
        return false;
    }

    bool operator!=(const Rational &lhs, const Rational &rhs) {

        if (!(lhs == rhs)) {
            return true;
        } else {
            return false;
        }
    }


    Rational Rational::simplify() const {
        Rational temp;
        Integer gcd;
        gcd = Integer(gcd.gcd(this->den, this->num));
        temp.den = den / gcd;
        temp.num = num / gcd;
        return temp;
        return Rational();
    }

    Rational Rational::getValue() const {
        Rational temp;
        temp.den = this->den;
        temp.num = this->num;
        return temp;
    }


    std::string Rational::toString() const {
        std::string s;
        Integer whole, numerator, denomnator;
        int x = stoi(this->num.repr());
        int g = stoi(this->den.repr());
        if (abs(x) > abs(g)) {
            whole = this->num / this->den;
            int p = abs(stoi(this->num.repr()) % stoi(this->den.repr()));
            numerator = Integer(p);
            denomnator = Integer(abs(stoi(this->den.repr())));
            s = whole.repr() + "." + numerator.repr() + "/" + denomnator.repr();
            return s;
        } else if (abs(stoi(this->num.repr())) == abs(stoi(this->den.repr()))) {
            s = "1";
            return s;
        } else {
            s = this->num.repr() + "/" + this->den.repr();
            return s;
        }
        return "";
    }

    Rational Rational::convertToImproper(Integer w, Integer n, Integer d) {
        if (w == Integer(0)) {
            return Rational(n, d);
        } else {
            Rational temp;
            temp.den = d;
            Integer wholeSign = w.absValue();
            temp.num = (w * d) + wholeSign * n;
            return temp;
        }
        return Rational();
    }
};

