#include <stdio.h>
#include "inputInteger.h"
#include "pot.h"

int main()
{
    int x, n;
    x = inputIntegerWithMsg("Please input the x:");
    n = inputIntegerWithMsg("Please input the n:");
    printf("%d^%d = %d\n", x, n, pot(x, n));
    return 0;
}