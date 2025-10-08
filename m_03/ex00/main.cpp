
#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clap1("CPC0");
    ClapTrap clap2("CPC1");

    clap1.attack("Target1");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap1.attack("Target2");
    clap2.takeDamage(10);
    clap2.beRepaired(5);

    return 0;
}
