
#pragma once
#include "Fixed.hpp"
#include <iostream>


class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float x_val, const float y_val);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();
    Fixed getX() const;
    Fixed getY() const;
};
bool bsp(const Point a, const Point b, const Point c, const Point point);
