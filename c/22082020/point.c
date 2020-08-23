#include <stdlib.h>
#include <math.h>
#include "point.h"

struct Point
{
    double x;
    double y;
};

struct Point *makePoint(double x, double y)
{
    struct Point *p = malloc(sizeof(struct Point));
    p->x = x;
    p->y = y;
    return p;
}

double getDistance(struct Point *p1, struct Point *p2)
{
    double distx = p2->x - p1->x;
    double disty = p2->y - p1->y;
    return sqrt(distx * distx + disty * disty);
}