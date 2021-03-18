#include <stdio.h>

int main()
{
    int num;
    puts("Please input an integer:");
    while (scanf("%d", &num) == 0)
    {
        //clear the buffer
        //fflush(stdin);//doens't work
        scanf("%*c");
    }
    printf("You've inputted the following integer: %d\n", num);
    return 0;
}