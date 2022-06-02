#include <iostream>
#include "Integer.h"
#include "Rational.h"


using namespace cosc326;
using namespace std;

int main() {
    Rational t = Rational(Integer("1"), Integer("1"), Integer("2"));


    cout << t;

    return 0;
};

