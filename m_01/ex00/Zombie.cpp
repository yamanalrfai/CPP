
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){
    this->name = name;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << ": is gone." << std::endl;
}
