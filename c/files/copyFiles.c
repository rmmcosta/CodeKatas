#include <stdio.h>
#include <stdlib.h>

#define ARGC 3

int main(int argc, char *argv[])
{
    if (argc != ARGC)
    {
        printf("You need to indicate the origin file and the destination file!\n");
        return 1;
    }
    FILE *origin = fopen(argv[1], "r");
    FILE *destin = fopen(argv[2], "w");
    char *c = malloc(sizeof(char));
    while (fread(c, sizeof(char), 1, origin))
    {
        fwrite(c, sizeof(char), 1, destin);
    }
    free(c);
    fclose(origin);
    fclose(destin);
    return 0;
}