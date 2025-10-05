
#include "Weapon.hpp"

Weapon::Weapon(std::string s)
{
    this->type = s;
}
std::string Weapon::getType()
{
    return this->type;
}

void Weapon::setType(std::string s)
{
    this->type = s;
}

