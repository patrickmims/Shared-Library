#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

FILE *list_error();
void *new_node();
void list_insert(void **, const int);
/* To be implemented
 */
void list_destroy(struct Node *);
#endif
