#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

Fixed::Fixed(int const i) {
    std::cout << "Int constructor called" << std::endl;
    value = i << fractionalBits;
}

Fixed::Fixed(float const f) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(f * (1 << fractionalBits));
}

float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
