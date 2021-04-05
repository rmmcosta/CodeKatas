#include <stdio.h>
#include <stdlib.h>

typedef struct xpto
{
    int value;
} xpto;

void allocate(xpto **x);
void printIsNull(xpto *x);

int main(void)
{
    xpto *x = NULL;
    printIsNull(x);
    allocate(&x);
    printIsNull(x);
    return 0;
}

void allocate(xpto **x)
{
    *x = malloc(sizeof(xpto));
}

void printIsNull(xpto *x)
{
    if (x == NULL)
        printf("Is null\n");
    else
        printf("Is not null\n");
}