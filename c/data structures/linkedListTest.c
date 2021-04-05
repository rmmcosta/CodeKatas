#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "linkedList.h"

int main(void)
{
    int value = END;
    printf("Enter values and end with %d\n", END);
    node *list = NULL;
    printList(&list);
    while (true)
    {
        scanf("%d", &value);
        if (value == -1)
            break;
        else
        {
            printf("insert node\n");
            insertNode(&list, value);
        }
        scanf("%*c"); //clear buffer
    }
    printList(&list);
    insertAtPos(&list, 33, 2);
    printList(&list);
    insertAtPos(&list, 33, 0);
    printList(&list);
    insertAtPos(&list, 33, 3);
    printList(&list);
    insertAtPos(&list, 33, 10);
    printList(&list);
    insertAtPos(&list, 33, 5);
    printList(&list);
    freeList(&list);
    return 0;
}
