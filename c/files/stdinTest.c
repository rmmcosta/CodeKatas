#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 50

void getAndPrintWords(FILE *fp);

int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 2)
        fp = fopen(argv[1], "r");
    else
        fp = stdin;

    if (fp == NULL)
        fprintf(stderr, "Error trying to access data\n");
    else
        getAndPrintWords(fp);
    return 0;
}

void getAndPrintWords(FILE *fp)
{
    char *word = malloc(sizeof(char) * MAX_WORD_SIZE);
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (i > 0)
                printf("%s\n", word);
            i = 0;
            free(word);
            word = malloc(sizeof(char) * MAX_WORD_SIZE);
        }
        else
        {
            word[i++] = c;
        }
    }
}