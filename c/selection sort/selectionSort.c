#include <stdio.h>
#include <stdlib.h>

const int DEFAULTSIZE = 8;
int DEFAULTNUMS[] = {8, 4, 3, 5, 2, 1, 7, 6};

void selectionSort(int *nums, int size);

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int temp[argc - 1];
        for (int i = 0; i < argc - 1; i++)
            temp[i] = atoi(argv[i + 1]);
        selectionSort(temp, argc - 1);
    }
    else
        selectionSort(DEFAULTNUMS, DEFAULTSIZE);
}

void selectionSort(int *nums, int size)
{
    int swaps = 0;
    for (int i = 0; i < size; i++)
    {
        int smallest = i; //smallest number position
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[smallest])
                smallest = j;
        }
        if (smallest != i)
        {
            //swap
            int temp = nums[i];
            nums[i] = nums[smallest];
            nums[smallest] = temp;
            swaps += 1;
        }
    }
    //print the result
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("Swaps: %d\n", swaps);
}