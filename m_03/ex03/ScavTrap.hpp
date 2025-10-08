
#pragma once
#include "ClapTrap.hpp"
#include <string>

class ScavTrap: virtual public ClapTrap {
public:
    ScavTrap();
    ~ScavTrap();
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ScavTrap(const std::string &name);
    void guardGate();
};
