#include <stdio.h>

int main()
{
    const char *fileName = "coiso.txt";
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
        printf("Unable to open the file %s\n", fileName);
    else
    {
        printf("The file %s was opened with success\n", fileName);
        printf("what is inside the file:\n");
        int c;
        while ((c = fgetc(fp)) != EOF)
        {
            printf("%c", c);
        }
        printf("\nThe read is over\n");
        fclose(fp);
    }
    return 0;
}