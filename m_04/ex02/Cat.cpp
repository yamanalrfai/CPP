#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat"){
    brain = new Brain();
    std::cout << "Cat is created." << std::endl;
}

Cat::~Cat() {
    if (brain)
        delete brain;
    std::cout << "Cat is destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copied." << std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assigned." << std::endl;
    if (this != &other) {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}
