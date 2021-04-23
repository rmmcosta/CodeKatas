//the syntax to call this program is the following
//./show [-option] [f1...fn] [-option] [fi...fk] ... -ofile_out
//show only the characters according to the option
// -U only upper case letters
// -l only lower case letters
// -d or -D only digits
// the default option is -U
// by default the output is to the screen but can be to file_out when indicated

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define OPTIONSIGN '-'
#define UPPERCASE_OPTION 'U'
#define LOWERCASE_OPTION 'l'
#define DIGITS1_OPTION 'd'
#define DIGITS2_OPTION 'D'
#define DEFAULT_OPTION 'U'
#define OUTPUT_OPTION 'o'

enum option
{
    UPPER_CASE,
    LOWER_CASE,
    DIGITS
};

bool isCallValid(int argc, char **argv);
bool isWrite2File(char char1st, char char2nd);
void processFile2Screen(enum option o, char *fileName);
void processFile2File(enum option o, char *fileName, char *outFileName);
void processFile(enum option o, char *fileName, FILE *fp);
void getOutputFileName(const char *fileNameWithCommand, char **fileName);

int main(int argc, char **argv)
{
    if (isCallValid(argc, argv) == false)
    {
        printf("Wrong syntax!\nThe program will exit.\n");
        exit(1);
    }
    char *outFileName = malloc(sizeof(char) * 20);
    bool is2WriteFile = isWrite2File(argv[argc - 1][0], argv[argc - 1][1]);
    int argsMax = argc; //the default is the total args but if an output file is indicated
    //we must decrease 1
    if (is2WriteFile == true)
    {
        getOutputFileName(argv[argc - 1], &outFileName);
        printf("The output will be written to the file %s\n", outFileName);
        //clear what's inside the file
        FILE *tfp = fopen(outFileName, "w");
        fclose(tfp);
        argsMax = argc - 1;
    }
    else
        free(outFileName);
    enum option opt;
    int i = 1;
    while (i < argsMax) //the last option depends on whether the output file is indicated or not.
    {
        if (argv[i][0] != OPTIONSIGN)
            opt = UPPER_CASE;
        else
        {
            //printf("option %c\n", argv[i][1]);
            switch (argv[i][1])
            {
            case UPPERCASE_OPTION:
                opt = UPPER_CASE;
                break;
            case LOWERCASE_OPTION:
                opt = LOWER_CASE;
                break;
            case DIGITS1_OPTION:
            case DIGITS2_OPTION:
                opt = DIGITS;
                break;
            default:
                printf("Wrong option %c\n. The program will exit.\n", argv[1][1]);
                exit(1);
            }
            i++;
        }
        //printf("opt %d\n", opt);
        //we have 2 incrementors - one for the commands and another one for the files
        int j = i;
        //printf("initial j = %d\n", j);
        while (argv[j][0] == OPTIONSIGN)
            j++;
        //printf("final j = %d\n", j);
        while (j < argc && argv[j][0] != OPTIONSIGN)
        {
            //printf("process file with i = %d and argv[i] = %s\n", i, argv[i]);
            if (is2WriteFile == true)
                processFile2File(opt, argv[j], outFileName);
            else
                processFile2Screen(opt, argv[j]);
            j++;
        }
        i++;
        while (i < argc && argv[i][0] != OPTIONSIGN)
            i++;
        //printf("Ended processing files \n");
    }
    return 0;
}

bool isCallValid(int argc, char **argv)
{
    if (argc <= 1)
        return false;
    if (argc == 2)
    {
        if (argv[1][0] != OPTIONSIGN)
            return true;
        else
            return false;
    }
    if (isWrite2File(argv[argc - 1][0], argv[argc - 1][1]) == true)
    {
        if (argc >= 3)
            return true;
        else
            return false;
    }
    return true;
}

bool isWrite2File(char char1st, char char2nd)
{
    return char1st == OPTIONSIGN && char2nd == OUTPUT_OPTION ? true : false;
}

void getOutputFileName(const char *fileNameWithCommand, char **fileName)
{
    if (isWrite2File(fileNameWithCommand[0], fileNameWithCommand[1]) == false)
    {
        printf("Wrong call to getOutputFileName!\n");
        exit(1);
    }
    int i = 2, j = 0;
    while (fileNameWithCommand[i] != '\0')
    {
        (*fileName)[j++] = fileNameWithCommand[i++];
    }
}

void processFile2Screen(enum option o, char *fileName)
{
    //printf("process file 2 screen\n");
    processFile(o, fileName, stdout);
    fflush(stdout);
}
void processFile2File(enum option o, char *fileName, char *outFileName)
{
    FILE *fp = fopen(outFileName, "a");
    processFile(o, fileName, fp);
    fclose(fp);
}

void processFile(enum option o, char *fileName, FILE *fp)
{
    //fprintf(fp, "cenas e tal\n");
    fprintf(fp, "%s\n", fileName);
    FILE *fpread = fopen(fileName, "r");
    char readc;
    while ((readc = fgetc(fpread)) != EOF)
    {
        bool is2Print = false;
        if (o == UPPER_CASE && readc >= 'A' && readc <= 'Z')
            is2Print = true;
        if (o == LOWER_CASE && readc >= 'a' && readc <= 'z')
            is2Print = true;
        if (o == DIGITS && isdigit(readc))
            is2Print = true;
        if (is2Print == true)
            fprintf(fp, "%c", readc);
    }
    //printf("\nEnded while loop\n");
    fprintf(fp, "\n");
}