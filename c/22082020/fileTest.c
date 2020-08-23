#include "file.h"
#include "stdio.h"

int main()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}
