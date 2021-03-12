#include <stdio.h>
#include <stdlib.h>

const int DEFAULTSIZE = 8;
int DEFAULTNUMS[] = {8, 4, 3, 5, 2, 1, 7, 6};

void bubbleSort(int *nums, int size);

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int temp[argc - 1];
        for (int i = 0; i < argc - 1; i++)
        {
            temp[i] = atoi(argv[i + 1]);
        }
        bubbleSort(temp, argc - 1);
    }
    else
    {
        bubbleSort(DEFAULTNUMS, DEFAULTSIZE);
    }
    return 0;
}

void bubbleSort(int *nums, int size)
{
    int swap;
    int swaps = 0;
    do
    {
        swap = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                //swap
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                swap = 1;
                swaps += 1;
            }
        }
    } while (swap == 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("Swaps: %d\n", swaps);
}