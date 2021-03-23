#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE_NAME 25
#define MAX_SIZE_GRADE 2

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("You must input the grades file after the program %s\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open file %s\n", argv[1]);
        return 1;
    }
    char *name = malloc(sizeof(char) * MAX_SIZE_NAME);
    char *grade = malloc(sizeof(char) * MAX_SIZE_GRADE);
    int chint;
    int namei = 0;
    int gradei = 0;
    while ((chint = fgetc(file)) != EOF)
    {
        char ch = (char)chint;
        //printf("%d - %c\n", chint, ch);
        if (isdigit(ch))
            *(grade + (gradei++)) = ch;
        else if (ch == '\n')
        {
            gradei = 0;
            namei = 0;
            int gradeint = atoi(grade);
            if (gradeint > 10)
                printf("The student %s had a grade of %d\n", name, gradeint);
            free(name);
            free(grade);
            name = malloc(sizeof(char) * MAX_SIZE_NAME);
            grade = malloc(sizeof(char) * MAX_SIZE_GRADE);
        }
        else if (ch == ' ' || ch == '\t')
            continue;
        else
            *(name + (namei++)) = ch;
    }
    free(name);
    free(grade);
    fclose(file);
    return 0;
}