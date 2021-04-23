#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define OP_OUT "-o"

int main(int argc, char *argv[])
{
    FILE *fin, *fout = stdout;
    int i;             //to iterate over all parameters
    int ch;            //to read the characters from files
    char option = 'U'; //by default upper case -U
    //check if the last parameter is of type -oFile
    if (strncasecmp(argv[argc - 1], OP_OUT, strlen(OP_OUT)) == 0)
    {
        // wt - write text mode
        if ((fout = fopen(argv[argc - 1] + 2, "wt")) == NULL)
        {
            fprintf(stderr, "Error openning file %s\n", argv[argc - 1] + 2);
            exit(1);
        }
        else
            argc--; //last parameter already processed
    }
    //iterate over parameters
    for (i = 1; i < argc; i++)
    {
        //it's a command
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 'l':
            case 'U':
            case 'd':
            case 'D':
                option = argv[i][1];
                //any other option will be ignored
            }
        }
        else //it's a file
        {
            fprintf(fout, "%s\n", argv[i]);
            if ((fin = fopen(argv[i], "r")) == NULL)
                continue; //skip
            while ((ch = fgetc(fin)) != EOF)
            {
                switch (option)
                {
                case 'l':
                    if (islower(ch))
                        fputc(ch, fout);
                    break;
                case 'U':
                    if (isupper(ch))
                        fputc(ch, fout);
                    break;
                case 'd':
                case 'D':
                    if (isdigit(ch))
                        fputc(ch, fout);
                    break;
                }
            }
            fclose(fin);
            fputc('\n', fout);
        }
    }
    fclose(fout);
    return 0;
}