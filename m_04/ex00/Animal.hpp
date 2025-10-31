#pragma once
#include <string>
class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string &type);
        virtual ~Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        std::string getType() const;
};

