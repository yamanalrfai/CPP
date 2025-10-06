
#pragma once
#include <ostream>
class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        Fixed(int const i);
        Fixed(float const f);
        float toFloat() const;
        int toInt() const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
