#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int N = 4;
    Animal* animals[N];

    for (int i = 0; i < N; ++i)
    {
        if (i < N/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    Dog* d0 = dynamic_cast<Dog*>(animals[0]);
    Cat* c2 = dynamic_cast<Cat*>(animals[2]);
    if (d0 && c2)
    {
        d0->getBrain()->setIdea(0, "I want a bone.");
        c2->getBrain()->setIdea(0, "I want fish.");
    }

    // deep copy test
    Dog copyDog = *d0;
    std::cout << "Original dog idea[0]: " << d0->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog idea[0]:     " << copyDog.getBrain()->getIdea(0) << std::endl;
    copyDog.getBrain()->setIdea(0, "I want a ball.");
    std::cout << "After modifying copy" << std::endl;
    std::cout << "Original dog idea[0]: " << d0->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog idea[0]:     " << copyDog.getBrain()->getIdea(0) << std::endl;

    for (int i = 0; i < N; ++i)
        delete animals[i];

    return 0;
}
