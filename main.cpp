#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
int main() {


    Rational t;
    Rational x;


    x.whole = Integer(3);
    x.num = Integer(5);
    x.den = Integer(8);
    t.whole = Integer(5);
    t.num = Integer(3);
    t.den = Integer(4);
    std::cout << t;

    t = t.convertToImprop();
    std::cout << t;


    bool j = (Integer(4) == Integer(8));


   // std::cout << x/t;

    return 0;
}
