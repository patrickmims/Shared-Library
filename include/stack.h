#ifndef STACK_H
#define STACK_H

typedef struct
{
    char *name;
    int *data;
    int ptr;
    int size;
} stack_t;

int stack_is_empty();
int stack_is_full();
void peek();
void pop();
void show();

#endif
