#include <stdio.h>

int inputIntegerWithMsg(char *msg);

int inputInteger()
{
    return inputIntegerWithMsg("Please input an integer:");
}

int inputIntegerWithMsg(char *msg)
{
    int integer;
    puts(msg);
    while (scanf("%d", &integer) == 0)
        scanf("%*c");
    return integer;
}