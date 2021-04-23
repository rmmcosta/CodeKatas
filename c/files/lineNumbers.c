#include <stdio.h>
#include <stdlib.h>

#define LINE_MAX_CHARS 100

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        fprintf(stderr, "Wrong sintax!\n");
        exit(1);
    }
    FILE *fpin = fopen(argv[1], "r");
    if (fpin == NULL)
    {
        fprintf(stderr, "Error openning file %s for read!\n", argv[1]);
        exit(1);
    }
    FILE *fpout = stdout;
    if (argc == 3)
    {
        fpout = fopen(argv[2], "w");
        if (fpout == NULL)
        {
            fprintf(stderr, "Error openning file %s for writting!\n", argv[2]);
            exit(1);
        }
    }
    int lineNumber = 0;
    char *line = malloc(sizeof(char) * LINE_MAX_CHARS);
    while (fgets(line, LINE_MAX_CHARS, fpin) != NULL)
    {
        lineNumber++;
        fprintf(fpout, "%d: %s", lineNumber, line);
    }
    fprintf(fpout, "\n");
    fclose(fpin);
    fclose(fpout);
    return 0;
}