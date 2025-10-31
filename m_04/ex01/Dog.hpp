#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>
class Dog : public Animal {
    private:
        Brain* brain;
    public:
        Dog();
        virtual ~Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual void makeSound() const;
        Brain* getBrain() const;
};
