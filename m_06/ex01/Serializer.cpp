#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& otherx) {
    (void)otherx;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* input) {
    return reinterpret_cast<uintptr_t>(input);
}

Data* Serializer::deserialize(uintptr_t input) {
    return reinterpret_cast<Data*>(input);
}
