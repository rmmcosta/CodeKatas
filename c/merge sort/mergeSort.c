#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

const int DEFAULTSIZE = 8;
int DEFAULTNUMS[] = {8, 7, 6, 5, 4, 3, 2, 1};

void mergeSort(int result[], int nums[], int size);
void printResult(int nums[], int size);
void merge(int result[], int left[], int right[], int leftSize, int RightSize);

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int size = argc - 1;
        int temp[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = atoi(argv[i + 1]);
        }
        int result[size];
        mergeSort(result, temp, size);
        printResult(result, size);
    }
    else
    {
        int result[DEFAULTSIZE];
        mergeSort(result, DEFAULTNUMS, DEFAULTSIZE);
        printResult(result, DEFAULTSIZE);
    }
    return 0;
}

void mergeSort(int result[], int nums[], int size)
{
    if (size == 1)
        return;

    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int left[leftSize];
    int right[rightSize];

    for (int i = 0; i < leftSize; i++)
        left[i] = nums[i];
    for (int i = 0; i < rightSize; i++)
        right[i] = nums[i + leftSize];

    mergeSort(left, left, leftSize);
    mergeSort(right, right, rightSize);

    merge(result, left, right, leftSize, rightSize);
}

void merge(int result[], int left[], int right[], int leftSize, int rightSize)
{
    int i = 0;
    int j = 0;
    int c = 0;
    while (i < leftSize || j < rightSize)
    {
        if (i == leftSize)
            result[c++] = right[j++];
        else if (j == rightSize)
            result[c++] = left[i++];
        else if (left[i] < right[j])
            result[c++] = left[i++];
        else
            result[c++] = right[j++];
    }
    printResult(result, leftSize + rightSize);
}

void printResult(int nums[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");
}