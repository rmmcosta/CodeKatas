#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char name[100];
    while (true)
    {
        puts("Name:");
        gets(name);
        if (strlen(name) == 0)//or name[0]=='\0'
            break;
        else
            printf("You've entered: %s\n", name);
    }
    return 0;
}