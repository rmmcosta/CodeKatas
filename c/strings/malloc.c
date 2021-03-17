#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s = (char *)malloc(sizeof(char) * 50);
    s = "Cosio e tal";
    printf("%s\n", s);
    s = "e depois cenas";
    printf("%s\n", s);
}