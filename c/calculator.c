#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef double (*operationPtr)(double, double);

typedef struct stack
{
    double value;
    struct stack *prev;
} stack;

double pop(stack **s);
void push(stack **s, double value);
void freeStack(stack **s);
void printStack(stack **s);

double multiply(double v1, double v2);
double divide(double dividend, double divisor);
double sum(double v1, double v2);
double sub(double v1, double v2);
double operation(operationPtr, double v1, double v2);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Wrong arguments!");
        exit(1);
    }
    int i = 0;
    char c;
    //initialize stack
    stack *s = NULL;
    //process calculations
    while ((c = argv[1][i++]) != '\0')
    {
        printf("char %c\n", c);
        stack *s2;
        if (isdigit(c))
            push(&s, c - '0');
        else if (c == '*')
            push(&s, operation(multiply, pop(&s), pop(&s)));
        else if (c == '/')
            push(&s, operation(divide, pop(&s), pop(&s)));
        else if (c == '+')
            push(&s, operation(sum, pop(&s), pop(&s)));
        else if (c == '-')
            push(&s, operation(sub, pop(&s), pop(&s)));
        else
        {
            printf("Wrong character %c\n", c);
            exit(1);
        }
    }
    printf("result %.2f\n", pop(&s));
    //freeStack(s);
    return 0;
}

double pop(stack **s)
{
    double value = (*s)->value;
    *s = (*s)->prev;
    printf("pop value %.2f\n", value);
    return value;
}

void push(stack **s, double value)
{
    printf("push the value: %.2f\n", value);
    stack *prev = *s;
    *s = malloc(sizeof(stack));
    (*s)->value = value;
    (*s)->prev = prev;
    printStack(s);
}

void freeStack(stack **s)
{
    while ((*s)->prev != NULL)
    {
        stack *temp = *s;
        (*s) = temp->prev;
        free(temp);
    }
    free(s);
}

void printStack(stack **s)
{
    stack *temp = *s;
    printf("The stack: ");
    while (temp->prev != NULL)
    {
        printf("current: %.2f, previous: %.2f\n", temp->value, temp->prev->value);
        temp = temp->prev;
    }
    printf("%.2f\n", temp->value);
}

double multiply(double v1, double v2)
{
    return v1 * v2;
}

double divide(double dividend, double divisor)
{
    return dividend / divisor;
}

double sum(double v1, double v2)
{
    return v1 + v2;
}

double sub(double v1, double v2)
{
    return v1 - v2;
}

double operation(operationPtr op, double v1, double v2)
{
    return op(v1, v2);
}