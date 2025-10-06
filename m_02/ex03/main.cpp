#include <iostream>
#include "Point.hpp"
int main( void ) {
    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);
    Point point(10, 30);

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}