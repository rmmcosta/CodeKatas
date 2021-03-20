#include <stdio.h>
#include "inputInteger.h"

void countDown(int n);

int main()
{
    countDown(inputInteger());
    return 0;
}

void countDown(int n)
{
    printf("%d\n", n);
    if (n <= 0)
    {
        return;
    }
    else
    {
        countDown(n - 1);
    }
}