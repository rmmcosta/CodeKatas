#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define COMMAND_SIGN '-'
#define COMMAND_TOTAL 't'
#define LINE_MAX_CHARS 24
#define OPER_MAX 12
#define MINUS_SIGN '-'
#define SUM_OPER '+'
#define SUB_OPER '-'
#define MULT_OPER '*'
#define DIV_OPER '/'
#define EQ_SIGN '='

void checkWrongSyntax(int argc, char **argv);
void printWrongSyntax();

typedef enum operation
{
    SUM,
    SUB,
    MULT,
    DIV,
    NONE
} operation;

int main(int argc, char **argv)
{
    checkWrongSyntax(argc, argv);
    bool onlyTotal = argc == 3 ? true : false;
    FILE *fpin;
    char *fileInName;
    //the following code is less optimal but more legible
    //a more performant alternative would be to always check only
    //total and go to the argv[1] or 2.
    if (onlyTotal == true)
    {
        fileInName = malloc(sizeof(char) * strlen(argv[2]) + 1);
        strcpy(fileInName, argv[2]);
    }
    else
    {
        fileInName = malloc(sizeof(char) * strlen(argv[1]) + 1);
        strcpy(fileInName, argv[1]);
    }
    fpin = fopen(fileInName, "r");
    if (fpin == NULL)
    {
        fprintf(stderr, "Error while trying to open file %s for read!\n", fileInName);
        free(fileInName);
    }

    free(fileInName);

    char *line = malloc(sizeof(char) * LINE_MAX_CHARS);

    double total = 0;

    while (fgets(line, LINE_MAX_CHARS, fpin) != NULL)
    {
        char *oper1 = malloc(sizeof(char) * OPER_MAX);
        char *oper2 = malloc(sizeof(char) * OPER_MAX);
        int lineI = 0, operI = 0;
        bool isOper1 = true;
        operation oper = NONE;
        while (lineI < strlen(line))
        {
            if ((operI == 0 && line[lineI] == MINUS_SIGN) || isdigit(line[lineI]))
            {
                if (isOper1 == true)
                    oper1[operI] = line[lineI];
                else
                    oper2[operI] = line[lineI];
                operI++;
                lineI++;
            }
            else
            {
                operI = 0;
                isOper1 = false;
                switch (line[lineI])
                {
                case SUM_OPER:
                    oper = SUM;
                    lineI++;
                    break;
                case SUB_OPER:
                    oper = SUB;
                    lineI++;
                    break;
                case MULT_OPER:
                    oper = MULT;
                    lineI++;
                    break;
                case DIV_OPER:
                    oper = DIV;
                    lineI++;
                    break;
                case '\n':
                    lineI++;
                    break;
                default:
                    fprintf(stdout, "Wrong data %c!\n", line[lineI]);
                    lineI = strlen(line);
                    break;
                }
            }
        }
        switch (oper)
        {
        case SUM:
            if (!onlyTotal)
                fprintf(stdout, "%d %c %d = %d\n", atoi(oper1), '+', atoi(oper2), atoi(oper1) + atoi(oper2));
            total += atoi(oper1) + atoi(oper2);
            break;
        case SUB:
            if (!onlyTotal)
                fprintf(stdout, "%d %c %d = %d\n", atoi(oper1), '-', atoi(oper2), atoi(oper1) - atoi(oper2));
            total += atoi(oper1) - atoi(oper2);
            break;
        case MULT:
            if (!onlyTotal)
                fprintf(stdout, "%d %c %d = %d\n", atoi(oper1), '*', atoi(oper2), atoi(oper1) * atoi(oper2));
            total += atoi(oper1) * atoi(oper2);
            break;
        case DIV:
            if (!onlyTotal)
                fprintf(stdout, "%d %c %d = %d\n", atoi(oper1), '/', atoi(oper2), atoi(oper1) / atoi(oper2));
            total += atoi(oper1) / atoi(oper2);
            break;
        }
        lineI = 0;
        free(oper1);
        free(oper2);
    }
    free(line);
    fprintf(stdout, "%.2f\n", total);
    fclose(fpin);
    return 0;
}

void checkWrongSyntax(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        printWrongSyntax();
        exit(1);
    }
    if (argc == 3)
    {
        if (argv[1][0] != COMMAND_SIGN || argv[1][1] != COMMAND_TOTAL)
        {
            printWrongSyntax();
            exit(1);
        }
    }
}
void printWrongSyntax()
{
    fprintf(stderr, "Wrong syntax!\nThe syntax must be: ./procCalc [-t] File\n");
}