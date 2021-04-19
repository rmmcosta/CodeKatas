#include <stdlib.h>
#include <stdio.h>

void print2Stdout(FILE *fp, char *text);

int main()
{
    fprintf(stdout, "cenas e coisas\n");
    print2Stdout(stdout, "coisas e tal");
    return 0;
}

void print2Stdout(FILE *fp, char *text)
{
    fprintf(fp, "%s\n", text);
}