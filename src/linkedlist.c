#include "linkedlist.h"

FILE *linkedlist_error()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("linkedlist_error.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

void *new_node()
{
    void *node = NULL; 

    if((node = malloc(sizeof(void *))) == NULL)
        fprintf(linkedlist_error(), "Error: new_node()\n");

    return node;
}

void list_insert(void **list, const int item)
{
    struct Node n;
    struct Node *node = &n;

    node = (struct Node *)new_node();

    node->data = item;
    node->next = *list;

    *list = node;

    printf("Item inserted: %d\n", item);
} 
