#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char name[100];
    int tries = 0;
    while (true)
    {
        if (tries > 0)
        {
            //clear the buffer
            scanf("%*[^\n]");
            scanf("%*c");
        }
        puts("Name:");
        scanf("%[a-zA-Z ]", name);
        //printf("1st char:%c\n", name[0]);
        if (name[0] == '\0')
            break;
        else
            printf("You've entered: %s\n", name);
        name[0] = '\0';
        tries++;
    }
    return 0;
}