#include <stdio.h>
#include <time.h>

typedef int (*fibofunc)(int);

int fiborec(int n);
int fibo(int n);

void runAndPrint(fibofunc, int n, char *strFunc);

int main()
{
    runAndPrint(fibo, 35, "fibo(35)");
    runAndPrint(fiborec, 35, "fiborec(35)");
    runAndPrint(fibo, 40, "fibo(40)");
    runAndPrint(fiborec, 40, "fiborec(40)");
    return 0;
}

int fiborec(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fiborec(n - 1) + fiborec(n - 2);
}

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int resultMinus1 = 1;
    int resultMinus2 = 0;
    int result;
    for (int i = 2; i <= n; i++)
    {
        result = resultMinus1 + resultMinus2;
        resultMinus1 = resultMinus2;
        resultMinus2 = result;
    }
    result = resultMinus1 + resultMinus2;
    return result;
}

void runAndPrint(fibofunc ff, int n, char *strFunc)
{
    long initTime;
    time(&initTime);
    int x;
    x = ff(n);
    long endTime;
    time(&endTime);
    printf("result of %s = %d, took:%ld\n", strFunc, x, endTime - initTime);
}