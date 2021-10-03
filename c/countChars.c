#include <stdio.h>

int main()
{
    int nc = 0;
    char c;
    while ((c = getchar()) != EOF) //ctrl+D
    {
        putchar(c);
        if (c != '\n')
            ++nc;
    }
    printf("total read chars: %d", nc);
    return 0;
}