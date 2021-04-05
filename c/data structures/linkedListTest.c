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
    freeList(&list);
    return 0;
}
