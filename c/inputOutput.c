#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF)
        printf("inputted: %c\n", c);
    return 0;
}