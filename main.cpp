#include <iostream>
#include "src/Integer.h"

int main() {
    Integer a = Integer(10);
    Integer b = Integer(4);
    Integer gcd = Integer::gcd(a, b);
    std::cout << gcd << std::endl;
    return 0;
}
