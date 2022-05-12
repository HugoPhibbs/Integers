#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
int main() {

    Rational imp = Rational("2/4");
    Rational temp = Rational("10.2/5");
    if(temp != imp) {
        std::cout << imp * temp;

    }
    return 0;
};

