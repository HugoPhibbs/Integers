#include <iostream>
#include "Integer.h"

using namespace cosc326;
using namespace std;
int main() {
    cout << "Welcome to Rationals!";
    Integer g = Integer("10");
    Integer t = Integer("5");

    cout << g;
    cout << t;
    cout << g/t;

    return 0;
};

