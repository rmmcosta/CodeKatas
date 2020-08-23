#include <stdio.h>
#include "point.h"

int main()
{
    struct Point *p1 = makePoint(2.0, 3.0);
    struct Point *p2 = makePoint(4.0, 5.0);
    double dist = getDistance(p1, p2);
    printf("Distance %.2f\n", dist);
    return 0;
}