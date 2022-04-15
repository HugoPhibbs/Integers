//
// Created by Hugo on 14/04/2022.
//

#include "Integer.h"

Integer::Integer() {

}

Integer::Integer(const std::string& digits) {
    value = std::stoi(digits);
}

Integer Integer::gcd(Integer a , Integer b) {
    //TODO does this work for negative values??
    a.setValue(abs(a.getValue()));
    b.setValue(abs(b.getValue()));
    if (a.getValue() == 0) {
        return b;
    }
    else if (b.getValue() == 0) {
        return a;
    }
    Integer remainder = a % b;
    return gcd(b, remainder);
}

Integer::~Integer() = default;

int Integer::getValue() const {
    return value;
}

Integer Integer::operator+(const Integer& b) const {
    return Integer(getValue() + b.getValue());
}

Integer Integer::operator*(const Integer &b) const {
    return Integer(getValue() * b.getValue());
}

Integer Integer::operator-(const Integer &b) const {
    return Integer(getValue() - b.getValue());
}

Integer Integer::operator/(const Integer &b) const {
    return Integer(getValue() /  b.getValue());
}

Integer Integer::operator%(const Integer &b) const {
    return Integer(getValue() % b.getValue());
}

Integer Integer::operator+=(const Integer &b) {
    *this=Integer(*this+b);
    return *this;
}

Integer Integer::operator*=(const Integer &b) {
    *this = Integer(*this * b);
    return *this;
}

Integer Integer::operator-=(const Integer &b) {
    *this = Integer(*this-b);
    return *this;
}

Integer Integer::operator/=(const Integer &b) {
    *this = Integer(*this/b);
    return *this;
}

Integer Integer::operator%=(const Integer &b) {
    *this = Integer(*this%b);
    return *this;
}

bool Integer::operator==(const Integer &b) const {
    return getValue() == b.getValue();
}

bool Integer::operator!=(const Integer &b) const{
    return !(*this==b);
}

bool Integer::operator<=(const Integer &b) const {
    return (*this==b) || (*this<b);
}

bool Integer::operator>=(const Integer &b) const {
    return (*this==b) || (*this>b);
}

bool Integer::operator<(const Integer &b) const {
    return getValue() < b.getValue();
}

bool Integer::operator>(const Integer &b) const {
    return getValue() > b.getValue();
}

Integer::Integer(const int val) {
    value = val;
}

Integer Integer::operator-() const {
    return Integer(-getValue());
}

Integer Integer::operator+() const {
    return Integer(+getValue());
}

std::ostream& operator<<(std::ostream &output, Integer &b) {
    output << b.getValue() << std::endl;
    return output;
}

std::istream& operator>>(std::istream &input, Integer &b) {
    input >> b.value;
    return input;
}

void Integer::setValue(int val) {
    value = val;
}

