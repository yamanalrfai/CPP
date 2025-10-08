
#include "ClapTrap.hpp"
#include <iostream>
#include "ScavTrap.hpp"
ScavTrap::ScavTrap(): ClapTrap(){
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->energyPoints = 50;
    this->hitPoints = 100;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
    this->energyPoints = 50;
    this->hitPoints = 100;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}
