//head [-n] file
//the -n is not mandatory and by default is 10
//returns the first n lines

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10
#define LINE_SIZE 1000

int main(int argc, char **argv)
{
    FILE *fp;
    int maxLines = DEFAULT_LINES;
    if (argc == 2)
        fp = fopen(argv[1], "r");
    else if (argc == 3)
    {
        fp = fopen(argv[2], "r");
        maxLines = atoi(argv[1]) * -1;
    }
    else
    {
        printf("Wrong arguments\n");
        exit(1);
    }
    if (fp == NULL)
    {
        printf("Unable to open file\n");
        exit(1);
    }
    char *line = malloc(sizeof(char) * LINE_SIZE);
    int lines = 0;
    while (fgets(line, LINE_SIZE, fp) != NULL && lines < maxLines)
    {
        fprintf(stdout, "%s", line);
        free(line);
        line = malloc(sizeof(char) * LINE_SIZE);
        lines++;
    }
    return 0;
}