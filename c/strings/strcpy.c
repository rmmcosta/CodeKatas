#include <stdio.h>

char *mystrcpy(char *dest, char *orig);

int main()
{
    char destString[100];
    mystrcpy(destString, "Ricardo");
    printf("1st dest string: %s\n", destString);
    char destString2[100];
    mystrcpy(destString2, mystrcpy(destString, "Carolina"));
    printf("2nd dest string: %s\n", destString2);
    return 0;
}

char *mystrcpy(char *dest, char *orig)
{
    printf("origin: %s\n", orig);
    printf("destin: %s\n", dest);
    char *initial = dest;
    while (*orig != '\0')
    {
        *(dest++) = *(orig++);
    }
    return initial;
}