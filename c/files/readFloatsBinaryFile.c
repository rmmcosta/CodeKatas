#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Wrong sintax. You must execute this program followed by the binary file you want to read.\n");
        exit(1);
    }
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        printf("Something went wrong when trying to open the file %s\n", argv[1]);
        exit(1);
    }
    else
    {
        printf("File %s opened with success!\n", argv[1]);
    }
    float readFloat;
    while (fread(&readFloat, sizeof(float), 1, fp) != 0)
    {
        printf("%f\n", readFloat);
    }
    fclose(fp);
    return 0;
}