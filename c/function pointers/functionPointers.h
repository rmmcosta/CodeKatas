#ifndef OPERATIONPOINTER_H
#define OPERATIONPOINTER_H
typedef int (*operationPtr)(int, int);

int sum(int, int);
int mult(int, int);
int doOper(operationPtr, int x, int y);
#endif