#include <stdio.h>
#include <stdlib.h>

float max(float v[], int n);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("You must input some float numbers!\n");
        return 1;
    }
    float temp[argc - 1];
    for (int i = 0; i < argc - 1; i++)
        temp[i] = atof(argv[i + 1]);
    printf("the max inputed value is: %.2f\n", max(temp, argc - 1));
    return 0;
}

float max(float v[], int n)
{
    float tempMax = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > tempMax)
            tempMax = v[i];
    return tempMax;
}