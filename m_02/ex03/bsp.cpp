
#include "Point.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point) {
    Fixed area_abc = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY())));
    if (area_abc < Fixed(0))
        area_abc = area_abc * Fixed(-1);
    Fixed area_abp = ((a.getX() * (b.getY() - point.getY())) + (b.getX() * (point.getY() - a.getY())) + (point.getX() * (a.getY() - b.getY())));
    if (area_abp < Fixed(0))
        area_abp = area_abp * Fixed(-1);
    Fixed area_acp = ((a.getX() * (point.getY() - c.getY())) + (point.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - point.getY())));
    if (area_acp < Fixed(0))
        area_acp = area_acp * Fixed(-1);
    Fixed area_bcp = ((point.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - point.getY())) + (c.getX() * (point.getY() - b.getY())));
    if (area_bcp < Fixed(0))
        area_bcp = area_bcp * Fixed(-1);
    if (area_acp == Fixed(0) || area_abp == Fixed(0) || area_bcp == Fixed(0))
        return false;
    if (area_abc == area_abp + area_acp + area_bcp)
        return true;
    return false;
}
