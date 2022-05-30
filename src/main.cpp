#include <iostream>
#include "Integer.h"
#include "Rational.h"


using namespace cosc326;
using namespace std;
int main() {



    Rational c = Rational("2/12");
    Rational t = Rational("1/12");
    cout << c-t;

    return 0;
};

