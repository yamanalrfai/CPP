#pragma once

#include <string>

class Weapon{
    private :
        std::string type;
    public :
        Weapon(std::string s);
        const std::string getType();
        void setType(std::string s);
};
