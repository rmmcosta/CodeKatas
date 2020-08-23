#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct ShapeInterface
{
    double (*Area)(void *instance);
} ShapeInterface;

typedef struct Shape
{
    void *instance;
    const ShapeInterface *interface;
} Shape;

Shape *shapeCreate(void *instance, ShapeInterface *interface)
{
    Shape *s = malloc(sizeof(Shape));
    s->instance = instance;
    s->interface = interface;
    return s;
}

double shapeArea(Shape *s)
{
    return (s->interface->Area)(s->instance);
}

typedef struct Square
{
    double sideLength;
} Square;

Square *squareCreate(double sideLength)
{
    Square *s = malloc(sizeof(Square));
    s->sideLength = sideLength;
    return s;
}
double squareArea(Square *s)
{
    return s->sideLength * s->sideLength;
}

ShapeInterface *squareAsShape = &(ShapeInterface){
    .Area = (double (*)(void *))squareArea};

typedef struct Circle
{
    double radius;
} Circle;

Circle *circleCreate(double radius)
{
    Circle *c = malloc(sizeof(Circle));
    c->radius = radius;
    return c;
}

double circleArea(Circle *c)
{
    return M_PI * (c->radius * c->radius);
}

ShapeInterface *circleAsShape = &(ShapeInterface){
    .Area = (double (*)(void *))circleArea};

int main()
{
    Square *square = squareCreate(3.0);
    Shape *squareShape = shapeCreate(square, squareAsShape);
    printf("Square area is: %.2f, and shape area is: %.2f\n",
           squareArea(square),
           shapeArea(squareShape));
    Circle *circle = circleCreate(2.0);
    Shape *circleShape = shapeCreate(circle, circleAsShape);
    printf("Circle area is: %.2f, and shape area is: %.2f\n",
           circleArea(circle),
           shapeArea(circleShape));
    return 0;
}