#include <stdio.h>
#include <stdlib.h>

int isPresent(int nums[], int value, int size);
int split(int nums[], int low, int high);
int min(int v1, int v2);
int max(int v1, int v2);

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        printf("Wrong number of inputs\nThe program will end\n");
        return 1;
    }
    int size = argc - 2;
    int nums[size];
    for (int i = 1; i <= size; i++)
        nums[i - 1] = atoi(argv[i]);
    int value = atoi(argv[argc - 1]);
    printf("inputted array: {");
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            printf("%i", nums[i]);
        else
            printf(", %i", nums[i]);
    }
    printf("}\nValue = %i\n", value);
    int result = isPresent(nums, value, ARRAYSIZE(nums));
    printf("The value %i is in the set: %s\n", value, result == 1 ? "true" : "false");
    return 0;
}

int isPresent(int nums[], int value, int size)
{
    if (size == 0)
        return 0;
    int middle = size / 2;
    int middleValue = nums[middle];
    if (middleValue == value)
        return 1;
    if (size == 1)
        return 0;
    if (middleValue > value)
    {
        int newSize = split(nums, 0, max(middle, 0));
        return isPresent(nums, value, newSize);
    }
    else
    {
        int newSize = split(nums, min(middle, size), size);
        return isPresent(nums, value, newSize);
    }
}

int split(int *nums, int low, int high)
{
    int newNums[high - low];
    int *oldPos = nums;
    int *newPos = nums+low;
    for (int i = low; i < high; i++)
    {
        *(oldPos++) = *(newPos++);
    }
    return ARRAYSIZE(newNums);
}

int min(int v1, int v2)
{
    if (v1 < v2)
        return v1;
    else
        return v2;
}

int max(int v1, int v2)
{
    if (v2 > v1)
        return v2;
    else
        return v1;
}