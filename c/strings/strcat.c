#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *string;

char *mystrcat(char *dest, char *orig);

int main()
{
    char s1[100] = "Ricardo";
    string s2 = "Costa";
    printf("%s\n", mystrcat(mystrcat(s1, " "), s2));
    return 0;
}

char *mystrcat(char *dest, char *orig)
{
    char *initial = dest; //initial position
    dest += strlen(dest); //position in the terminator
    while (*(orig) != '\0')
    {
        *(dest++) = *(orig++);
    }
    return initial;
}