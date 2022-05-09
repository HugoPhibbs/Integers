#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
int main() {

    Rational imp = Rational("1.2/4");
    Rational temp = Rational("-1.1/4");
    if(temp != imp){
        std::cout << imp/temp; // should return -1.1/5 but return -2
    }

    return 0;
};

