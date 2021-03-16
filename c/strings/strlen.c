#include <stdio.h>

int mystrlen(char *s);

int main()
{
    char str[100];
    puts("Please input a string without spaces: ");
    scanf("%s", str);
    printf("The size of %s is %d\n", str, mystrlen(str));
    return 0;
}

int mystrlen(char *s)
{
    int size = 0;
    while (*(s++) != '\0')
    {
        size++;
    }
    return size;
}