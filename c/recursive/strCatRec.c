#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strCat(char *s1, char *s2);
char *strCatRec(char *dest, char *s1, char *s2, int size);

int main()
{
    printf("%s\n", strCat(strCat("Ricardo", " "), "Costa"));
    char *dest = malloc(sizeof(char) * 14);
    printf("%s\n", strCatRec(dest, "Ricardo", " Costa", 13));
    free(dest);
    printf("%s\n", strCat("a", "b"));
    dest = malloc(sizeof(char) * 3);
    printf("%s\n", strCatRec(dest, "a", "b", 2));
    free(dest);
    return 0;
}

char *strCat(char *s1, char *s2)
{
    char *temp = malloc(sizeof(char) * strlen(s1) + sizeof(char) * strlen(s2) + 1);

    int i = 0;
    while (*(s1 + i) != '\0')
    {
        *(temp + i) = *(s1 + i);
        i++;
    }
    int j = 0;
    while (*(s2 + j) != '\0')
    {
        *(temp + i) = *(s2 + j);
        i++;
        j++;
    }
    *(temp + i) = '\0';
    return temp;
}

char *strCatRec(char *dest, char *s1, char *s2, int size)
{
    if (*s1 != '\0')
    {
        *dest = *s1;
        return strCatRec(dest + 1, s1 + 1, s2, size);
    }
    *dest = *s2;
    if (*s2 == '\0')
        return dest - size;
    return strCatRec(dest + 1, s1, s2 + 1, size);
}