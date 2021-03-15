#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 3
#define DEFAULT_SEPARATOR_SIZE 10
#define MAX_VALUE 9

void invert(int v[MAX][MAX]);
void invert2(int v[MAX][MAX]);
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
    invert2(matrix);
    printSeparator(DEFAULT_SEPARATOR_SIZE);
    printMatrix(matrix);
    return 0;
}

void invert(int v[MAX][MAX])
{
    int temp;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (i == MAX - i - 1 && j == MAX - j - 1)
                return;
            temp = v[i][j];
            v[i][j] = v[MAX - i - 1][MAX - j - 1];
            v[MAX - i - 1][MAX - j - 1] = temp;
        }
    }
}

void invert2(int v[MAX][MAX])
{
    int temp;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            temp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = temp;
        }
    }
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
            v[i][j] = rand() % MAX_VALUE + 1;
}

void printSeparator(int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("-");
    printf("\n");
}