#include "namedPoint.h"
#include <stdlib.h>
#include <string.h>

struct NamedPoint
{
    double x;
    double y;
    char *name;
};

struct NamedPoint *makeNamedPoint(double x, double y, char *name)
{
    struct NamedPoint *tp = malloc(sizeof(struct NamedPoint));
    tp->x = x;
    tp->y = y;
    tp->name = malloc(sizeof(strlen(name) + 1));
    strcpy(tp->name, name);
    return tp;
}

void setName(struct NamedPoint *p, char *name)
{
    p->name = malloc(sizeof(strlen(name) + 1));
    strcpy(p->name, name);
}

char *getName(struct NamedPoint *p)
{
    return p->name;
}
