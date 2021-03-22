#include <stdio.h>

int main()
{
    const char *fileName = "coiso.txt";
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL)
        printf("Unable to create the file %s\n", fileName);
    else
    {
        printf("The file %s was created with success\n", fileName);
        printf("What do you want to put in the file:\n");
        int c;
        while ((c = getchar()) != EOF)
        {
            fputc(c, fp);
        }
        printf("\nYou are done with the file\n");
        fclose(fp);
    }
    return 0;
}