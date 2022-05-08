#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
int main() {

    Rational temp = Rational("1/4");
    Rational imp = Rational("-14.5/4");
    Rational g = imp-temp;
    std::cout << g;

    return 0;
};

