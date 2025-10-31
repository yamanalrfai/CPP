#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog is created." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog is destroyed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assigned." << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
