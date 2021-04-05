#define END -1

typedef struct node
{
    int value;
    struct node *next;
} node;

void insertNode(node **list, int value);
void freeList(node **list);
void printList(node **list);