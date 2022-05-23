#include <iostream>
#include "src/Integer.h"
#include "src/Rational.h"

using namespace cosc326;
using namespace std;
int main() {
/*
    Rational imp = Rational("2/4");
    Rational temp = Rational("2/5");


    std::cout << temp;
    if(imp == imp){
        cout << "\n == working";
    }
    if(imp != temp){
        cout << "\n != working";
    }
    if(imp > temp){
        cout << "\n < working";
    }
    if(temp < imp){
        cout << "\n > working";
    }


    if((temp + imp) == Rational(Integer(9), Integer(10))){
        cout << "\n+ working";
    }

    if(temp-imp == Rational("-1/10")){
        cout << "\n- working";
    }
*/
    Rational t = Rational(Integer(965286), Integer(1));
    cout << t;
    return 0;
};

