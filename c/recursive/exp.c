#include <stdio.h>
#include "inputInteger.h"
#include "pot.h"

float myexp(int x, int t, int n);

int main()
{
    int x, t, n;
    x = inputIntegerWithMsg("Please input the x:");
    t = inputIntegerWithMsg("Please input the t:");
    n = inputIntegerWithMsg("Please input the n:");
    printf("Exp(%d,%d,%d) = %.4f\n", x, t, n, myexp(x, t, n));
    return 0;
}

float myexp(int x, int t, int n)
{
    if (n < 1)
        return 0;
    return (float)x / pot(1 + t, n) + myexp(x, t, n - 1);
}