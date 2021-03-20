#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int strCmpRec(char *s1, char *s2);

int main()
{
    char *s1 = malloc(sizeof(char) * 50);
    char *s2 = malloc(sizeof(char) * 50);
    while (true)
    {
        puts("Input 0 to quit");
        puts("Please input the 1st string:");
        scanf("%s", s1);
        if (strCmpRec(s1, "0") == 0)
            exit(0);
        puts("Please input the 2nd string:");
        scanf("%s", s2);
        if (strCmpRec(s2, "0") == 0)
            exit(0);
        printf("compare result: %d\n", strCmpRec(s1, s2));
    }
    free(s1);
    free(s2);
    return 0;
}

int strCmpRec(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    if (*s1 == *s2)
        return strCmpRec(s1 + 1, s2 + 1);
    return *s1 - *s2;
}