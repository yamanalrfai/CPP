#pragma once
#include <string>
class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string t);
         ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
         void makeSound() const;
        std::string getType() const;
};
