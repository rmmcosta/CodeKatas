#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 5
#define DEFAULT_SEPARATOR_SIZE 10

void invert(int v[MAX][MAX]);
void printMatrix(int v[MAX][MAX]);
void fillMatrix(int v[MAX][MAX]);
void printSeparator(int n);

int main()
{
    int matrix[MAX][MAX];
    fillMatrix(matrix);
    printSeparator(DEFAULT_SEPARATOR_SIZE);
    printMatrix(matrix);
    invert(matrix);
    printSeparator(DEFAULT_SEPARATOR_SIZE);
    printMatrix(matrix);
    return 0;
}

void invert(int v[MAX][MAX])
{
}

void printMatrix(int v[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            printf("%2d ", v[i][j]);
        printf("\n\n");
    }
}

void fillMatrix(int v[MAX][MAX])
{
    long ultime;
    time(&ultime);
    srand(ultime);
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            v[i][j] = rand() % 99 + 1;
}

void printSeparator(int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("-");
    printf("\n");
}