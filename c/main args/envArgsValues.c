#include <stdio.h>

int main(int argc, char **argv, char **envargs)
{

    for (int i = 0; envargs[i] != NULL; i++)
    {
        int j = 0;
        while (envargs[i][j] != '=')
            j++;
        while (envargs[i][++j] != '\0')
            printf("%c", envargs[i][j]);
        printf("\n");
    }
}