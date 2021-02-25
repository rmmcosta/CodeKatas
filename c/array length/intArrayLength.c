#include <stdio.h>

#define ARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))

int main(void) {
    int arr[] = {1,2,3,4,5};
    int size = ARRAYSIZE(arr);
    printf("the size of the array is %i\n", size);
    int arr2[] = {};
    size = ARRAYSIZE(arr2);
    printf("the size of the array2 is %i\n", size);
    return 0;
}