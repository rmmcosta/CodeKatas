#include <stdio.h>
#include <stdlib.h>

int main()
{
    int upperBound = 5;
    int lowerBound = 1;
    for (int i = 0; i < 10; i++)
        printf("%d\n", rand() % upperBound + lowerBound);
    return 0;
}