#include "namedPoint.h"
#include "point.h"
#include <stdio.h>

int main()
{
    struct NamedPoint *np1 = makeNamedPoint(0.0, 0.0, "origin");
    struct NamedPoint *np2 = makeNamedPoint(2.0, 2.0, "middle");
    printf("The distance from %s to %s is %.2f.\n",
           getName(np1),
           getName(np2),
           getDistance((struct Point *)np1, (struct Point *)np2));
    printf("let's change the np2 name\n");
    setName(np2, "myPoint");
    printf("And the new name for np2 is %s\n", getName(np2));
    char *n = "xpto";
    struct NamedPoint *np3 = makeNamedPoint(5.0, 10.0, n);
    printf("n = %s, np3 name = %s\n", n, getName(np3));
    n = "coiso";
    printf("n = %s, np3 name = %s\n", n, getName(np3));
    return 0;
}