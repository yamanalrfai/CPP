
#pragma once
#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
public:
    FragTrap();
    ~FragTrap();
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    FragTrap(const std::string &name);
    void highFivesGuys();
};
