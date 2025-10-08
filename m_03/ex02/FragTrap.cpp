#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap(){
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->energyPoints = 100;
    this->hitPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
    this->energyPoints = 100;
    this->hitPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}
