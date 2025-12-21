#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

Base::~Base() {}

Base * generate(void){
    int random = rand() % 4;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else if (random == 2)
        return new C();
    else
        return new D();
}

void identify(Base* p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "is a A pointer" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p)) {
        std::cout << "is a B pointer" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p)) {
        std::cout << "is a C pointer" << std::endl;
        return;
    }
    std::cout << "not in the (A, B, C) group" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A &>(p);
        std::cout << "is a A pointer" << std::endl;
        return;
    }
    catch(...){};
    try {
        dynamic_cast<B &>(p);
        std::cout << "is a B pointer" << std::endl;
        return;
    }
    catch(...){};
    try {
        dynamic_cast<C &>(p);
        std::cout << "is a C pointer" << std::endl;
        return;
    }
    catch(...){};
    std::cout << "not in the (A, B, C) group" << std::endl;

}
