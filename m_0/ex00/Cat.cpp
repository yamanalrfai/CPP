#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat"){
    std::cout << "Cat is created." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat is destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assigned." << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
