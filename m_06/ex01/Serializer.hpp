#pragma once

#include <cstdint>
struct Data {
    int value;
};

class Serializer {
public:
    Serializer();
    ~Serializer();
    Serializer& operator=(const Serializer&);
    Serializer(const Serializer& otherx);
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
