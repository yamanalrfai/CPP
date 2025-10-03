
#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie* heapZombie = newZombie("i am in the heap :)");
    heapZombie->announce();
    
    randomChump("i am in the stack :)");
    delete heapZombie;
    return 0;
}
