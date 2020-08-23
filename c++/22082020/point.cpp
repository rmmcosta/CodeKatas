#include "point.hpp"
#include <cmath>

double Point::getDistance(const Point &p2) const
{
    double distx = p2.x - this->x;
    double disty = p2.y - this->y;
    return sqrt(distx * distx + disty * disty);
}