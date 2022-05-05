#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
int main() {


    Rational t;
    Rational x;

    Rational imp1 = Rational(Integer(1), Integer(3));
    Rational imp2 = Rational(Integer(2), Integer(5));
    imp1/=imp2;
    std::cout << imp1;


    t.whole = Integer(5);
    t.num = Integer(3);
    t.den = Integer(4);

    x.whole = Integer(5);
    x.num = Integer(3);
    x.den = Integer(4);
    //std::cout << (t + x).convertToImprop();

    //std::cout << x.convertToImprop();



    bool j = (Integer(4) == Integer(8));


   // std::cout << x/t;

    return 0;
}
