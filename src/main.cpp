#include <iostream>
#include "Integer.h"
#include "Rational.h"


using namespace cosc326;
using namespace std;

int main() {
    Rational t = Rational("-1/2");
    Rational g = Rational("-3/2");
    cout << t/g;
    return 0;
};

