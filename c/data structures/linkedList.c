#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insertNode(node **list, int value)
{
    //list is empty
    if (*list == NULL)
    {
        printf("The list is null\n");
        *list = malloc(sizeof(node));
        if (*list == NULL)
        {
            printf("failed to initialize list\n");
            exit(1);
        }
        (*list)->value = value;
        (*list)->next = NULL;
    }
    else
    {
        printf("list is not null\n");
        node *temp = *list;
        printf("temp pointing to list\n");
        if (temp == NULL)
        {
            printf("Failed to point to the list\n");
            exit(1);
        }
        while (temp->next != NULL)
            temp = temp->next;
        printf("positioned in the end of the list\n");
        temp->next = malloc(sizeof(node));
        temp->next->value = value;
        temp->next->next = NULL;
    }
}

void insertAtPos(node **list, int value, int pos)
{
    if (pos < 0)
    {
        printf("Position must be a positive number\n");
        return;
    }
    int i = 0;
    node *current = *list;
    node *prev = *list;
    while (i < pos && current->next != NULL)
    {
        i++;
        prev = current;
        current = current->next;
    }
    if (current->next == NULL && i < pos)
    {
        printf("Invalid Position! Max position is %d\n", i);
    }
    else
    {
        printf("insert in pos %d\n", pos);
        node *oldCurrent = current;
        current = malloc(sizeof(node));
        current->value = value;
        current->next = oldCurrent;
        if (pos > 0)
            prev->next = current;
        else
            *list = current;
    }
}

void printList(node **list)
{
    printf("The List\n");
    if (*list == NULL)
        return;
    printf("The values\n");
    node *temp = *list;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("%d\n", temp->value); //last value
}

void freeList(node **list)
{
    node *temp = *list;
    while (temp->next != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
}