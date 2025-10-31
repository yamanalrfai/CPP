#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal is created." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal is destroyed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal copied." << std::endl;
    type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal assigned." << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t) : type(t) {
    std::cout << "WrongAnimal is created." << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}
