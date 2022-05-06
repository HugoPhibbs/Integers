#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
int main() {
    //Rational r = Rational("0.9/4");
   // std:: cout << r.convertToImprop();
    /*Integer i = Integer(5);
    Integer g = Integer(4);
    if (i > g) {

    }


    Rational t;
    Rational x;

    Rational imp1 = Rational(Integer(1), Integer(3));
    Rational imp2 = Rational(Integer(8), Integer(5));

    //std::cout << imp1+imp2;


    t.whole = Integer(5);
    t.num = Integer(3);
    t.den = Integer(4);

    x.whole = Integer(5);
    x.num = Integer(10);
    x.den = Integer(8);

    // x = x.simplify();

    //std::cout << t + x;




    bool j = (Integer(4) == Integer(8));


    // std::cout << x/t;
     *//*
    std::string str("100/4");
    Rational temp;

    std::size_t foundSlash = str.find("/");
   // if (foundSlash != std::string::npos) {

        std::string num = str.substr(0, foundSlash);
        std::string den = str.substr(foundSlash+1, foundSlash-str.length()+1);
        int numberN = stoi(num);
        int numberD = stoi(den);
        std::cout << numberN;
        //std::cout << numberD;

        /*
        int numberW = stoi(wholeS);
        int numberN = stoi(num);
        int numberD = stoi(den);
        temp.whole = Integer(numberW);
        temp.num = Integer(numberN);
        temp.den = Integer(numberD);
        Rational g = temp.convertToImprop();
        std::cout << g;
         */

    Rational temp = Rational("+1/4");
    Rational imp = Rational("3.5/4");
    std::cout << temp+imp;

    return 0;
};

