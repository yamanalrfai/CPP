#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(const std::string &typ) : type(typ) {
    std::cout << "Animal of type " << typ << " created." << std::endl;
}

Animal::Animal() : type("ANIMAL") {
    std::cout << "Animal of unknown type created." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal of type " << type << " destroyed." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal of type " << type << " copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal of type " << type << " assigned." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

void Animal::makeSound() const{
    std::cout << "ANIMAL SOUND" << std::endl;
}

std::string Animal::getType() const{
    return type;
}
