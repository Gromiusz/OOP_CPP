#include <iostream>
#include <algorithm>
#include "fraction.hpp"

int main(){
    fraction a(6,4);
    a++;
    std::cout << a;
    std::cout << std::endl;

    fraction b(1,4);
    fraction c(1,6);
    b +=c;
    std::cout << b;
    std::cout << std::endl;

    fraction d(1,2);
    fraction e(1,3);
    bool res = d<=e;
    std::cout << res << std::endl;
    std::cout << std::endl;

    fraction f;
    std::cout << f;
    f = e;
    std::cout << f;
    std::cout << std::endl;

    fraction g(std::move(c));
    std::cout << c;
    std::cout << g;
    std::cout << std::endl;

    fraction h(3,0);
    fraction i(0,3);
    b/=i;
    std::cout << b;
    fraction j(-1,3);
    fraction k(-1,-3);
    j*=fraction(-1,3);
    std::cout << j;
}