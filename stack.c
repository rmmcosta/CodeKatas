#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int value;
    struct stack *prev;
} stack;

void push(stack **s, int value);
int pop(stack **s);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("wrong arguments!\n");
        exit(1);
    }
    char c;
    int i = 0;
    stack *s = NULL;
    while ((c = argv[1][i++]) != '\0')
    {
        push(&s, c - '0');
    }

    //print the stack
    stack *prints = s;
    printf("Lets print the stack!\n");
    while (prints != NULL)
    {
        printf("value: %d\n", prints->value);
        prints = prints->prev;
    }
    free(prints);
    //free the stack
    stack *frees = s;
    while (s->prev != NULL)
    {
        frees = s->prev;
        free(s);
        s = frees;
    }
    free(s);
    //free(frees);
}

void push(stack **s, int value)
{
    stack *temp = *s;
    *s = malloc(sizeof(stack));
    (*s)->prev = temp;
    (*s)->value = value;
}

int pop(stack **s)
{
    stack *prev = (*s)->prev;
    int value = (*s)->value;
    free(*s);
    *s = prev;
    return value;
}