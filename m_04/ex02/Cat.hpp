#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>
class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual void makeSound() const;
        Brain* getBrain() const;
};
