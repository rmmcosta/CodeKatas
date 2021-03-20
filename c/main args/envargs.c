#include <stdio.h>

int main(int argc, char **argv, char **envargs)
{
    while (*envargs != NULL)
        printf("%s\n", *(envargs++));
    return 0;
}