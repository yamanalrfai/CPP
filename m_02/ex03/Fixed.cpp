#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed::Fixed(int const i) {
    value = i << fractionalBits;
}

Fixed::Fixed(float const f) {
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

Fixed &Fixed::operator++() {
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++value;
    return temp;
}

Fixed &Fixed::operator--() {
    --value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --value;
    return temp;
}

bool Fixed::operator>(const Fixed &other) const {
    return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

