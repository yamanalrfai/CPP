
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap scav1("SCP0");
    ScavTrap scav2("SCP1");

    scav1.attack("Target1");
    scav2.takeDamage(5);
    scav2.beRepaired(3);
    scav1.attack("Target2");
    scav2.takeDamage(10);
    scav2.beRepaired(5);
    scav2.guardGate();

    return 0;
}
