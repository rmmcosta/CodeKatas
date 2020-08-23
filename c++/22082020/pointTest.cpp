#include <iostream>
#include "point.hpp"

int main()
{
    Point *p1 = new Point(2.0, 3.0);
    Point *p2 = new Point(4.0, 5.0);
    double dist = p1->getDistance(*p2);
    std::cout << "distance " << dist << std::endl;
    return 0;
}