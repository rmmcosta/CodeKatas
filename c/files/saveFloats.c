#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOATS 10
#define FILE_NAME "floats.dat"

void checkSeekResult(FILE *fp, int seekResult);

int main()
{
    int writeOption;
    printf("Do you want to write the numbers again? (1-Yes, 0-No): ");
    scanf("%d", &writeOption);
    FILE *fp;
    if (writeOption == 1)
    {
        float floats[NUM_FLOATS];
        printf("Please input %d decimal numbers.\n", NUM_FLOATS);
        for (int i = 0; i < NUM_FLOATS; i++)
        {
            printf("Number %d:", i + 1);
            scanf("%f", &floats[i]);
        }
        fp = fopen(FILE_NAME, "w+b");
        if (fp == NULL)
        {
            printf("Unable to open %s\n", FILE_NAME);
            exit(1);
        }
        if (fwrite(floats, sizeof(float), NUM_FLOATS, fp) != NUM_FLOATS)
            printf("Something went wrong when writing %d floats to the file %s\n", NUM_FLOATS, FILE_NAME);
    }
    else
    {
        fp = fopen(FILE_NAME, "rb");
    }
    printf("Now, which number do you want to check:");
    int number;
    scanf("%d", &number);
    while (number < 1 || number > NUM_FLOATS)
    {
        printf("Wrong number!\n");
        scanf("%d", &number);
    }
    //lets position the fp in the correct line
    int seekResult = fseek(fp, (long)(number - 1) * sizeof(float), SEEK_SET);
    checkSeekResult(fp, seekResult);
    float readFloat;
    fread(&readFloat, sizeof(float), 1, fp);
    printf("At the position %d you've inserted the float %.2f\n", number, readFloat);
    rewind(fp);
    fread(&readFloat, sizeof(float), 1, fp);
    printf("The first inputted float was %.2f\n", readFloat);
    seekResult = fseek(fp, -sizeof(float), SEEK_END);
    checkSeekResult(fp, seekResult);
    fread(&readFloat, sizeof(float), 1, fp);
    printf("And the last one was %.2f\n", readFloat);
    fclose(fp);
    return 0;
}

void checkSeekResult(FILE *fp, int seekResult)
{
    if (seekResult != 0)
    {
        printf("Something went wrong when positioning in the file %d\n", seekResult);
        fclose(fp);
        exit(1);
    }
}