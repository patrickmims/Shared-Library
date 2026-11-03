#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int *data;
    int ptr;
    int size;
} stack_t;

stack_t *create_stack(int);

int stack_is_empty(stack_t *);
int stack_is_full(stack_t *);
int stack_peek(stack_t *);
void stack_push(stack_t *, const int);
void stack_pop(stack_t *);

#endif
