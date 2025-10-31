#include "WrongCat.hpp"
#include <iostream>
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat is created." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat is destroyed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat copied." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}
