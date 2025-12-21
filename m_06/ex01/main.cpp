#include <iostream>
#include "Serializer.hpp"

int main() {
    Data original;
    original.value = 42;

    std::cout << "Original Data address: " << &original << std::endl;
    std::cout << "Original Data value: " << original.value << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized (uintptr_t): " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;
    std::cout << "Deserialized Data value: " << deserialized->value << std::endl;

    if (deserialized == &original) {
        std::cout << "Success: Pointers match!" << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}
