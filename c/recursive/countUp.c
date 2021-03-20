#include <stdio.h>
#include "inputInteger.h"

void countUp(int n);

int main()
{
    countUp(inputInteger());
    return 0;
}

void countUp(int n)
{
    if (n < 0)
    {
        return;
    }
    else
    {
        countUp(n - 1);
    }
    printf("%d\n", n);
}