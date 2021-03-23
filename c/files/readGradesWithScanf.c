#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE_NAME 25

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
    int grade;
    while (fscanf(file, "%s %d", name, &grade) != EOF)
        if (grade > 10)
            printf("The student %s had a grade of %d\n", name, grade);
    free(name);
    fclose(file);
    return 0;
}