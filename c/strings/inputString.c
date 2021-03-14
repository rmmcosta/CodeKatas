#include <stdio.h>

int main()
{
    char s[100];
    printf("Please input a msg: ");
    scanf(" %[^\n]", s); //all characters minus the \n
    printf("your msg: %s\n", s);
    printf("Please input a number: ");
    scanf(" %[0-9{1,2}]", s);
    printf("your numbers: %s\n", s);
}
