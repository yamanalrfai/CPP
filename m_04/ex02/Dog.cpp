#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog") {
    brain = new Brain();
    std::cout << "Dog is created." << std::endl;
}

Dog::~Dog() {
    if (brain)
        delete brain;
    std::cout << "Dog is destroyed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copied." << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assigned." << std::endl;
    if (this != &other) {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
