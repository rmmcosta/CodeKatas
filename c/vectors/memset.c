#include <stdio.h>

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

char *mymemset(char v[], char c, int n);
void printVector(char vector[], int size);

int main()
{
    char vogals[] = {'a', 'e', 'i', 'o', 'u'};
    printVector(vogals, ARRAYSIZE(vogals));
    char *cenas;
    cenas = mymemset(vogals, 'x', 3);
    printVector(cenas, ARRAYSIZE(vogals));
    return 0;
}

char *mymemset(char v[], char c, int n)
{
    for (int i = 0; i < n; i++)
        v[i] = c;
    return v;
}

void printVector(char vector[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%c", vector[i]);
    printf("\n");
}
