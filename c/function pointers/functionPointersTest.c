#include <stdio.h>
#include "functionPointers.h"

int main()
{
    printf("please input two numbers.\n");
    int x, y;
    printf("first one:");
    scanf("%d", &x);
    printf("second one:");
    scanf("%d", &y);
    printf("the sum of those numbers is: %d\n", doOper(sum, x, y));
    printf("the multiplication of those numbers is: %d\n", doOper(mult, x, y));
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}

int mult(int x, int y)
{
    return x * y;
}

int doOper(operationPtr op, int x, int y)
{
    return op(x, y);
}