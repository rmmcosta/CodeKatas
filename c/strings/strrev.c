#include <stdio.h>
#include <string.h>

char *mystrrev(char *s);

int main()
{
    char *s = "Ricardo";
    printf("initial string %s\n", s);
    printf("reversed string %s\n", mystrrev(s));
    return 0;
}

char *mystrrev(char *s)
{
    char *initial = s;
    char *left = s;
    char *right = s + strlen(s) - 1;
    printf("left pointer %p and value %c\n", left, *left);
    printf("right pointer %p and value %c\n", right, *right);
    while (left < right)
    {
        char temp = *left;
        printf("temp %c\n", temp);
        *left = *right;
        printf("new left %c\n", *left);
        *right = temp;
        printf("new right %c\n", *right);
        left++;
        right--;
    }
    return initial;
}