#include <stdio.h>

int vectorlen(char *s);

int main()
{
    char *s = "ricardo";
    printf("The length of %s is %d\n", s, vectorlen(s));
    return 0;
}

int vectorlen(char *s)
{
    char *ptr = s;
    while (*ptr != '\0')
        ptr++;
    return (int)(ptr - s); //we don't need to add 1 because we are
    //incrementing ptr before evaluating it so we will be pointing to \0 in the end.
}