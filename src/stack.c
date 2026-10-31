#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

// stack_t *stack = create_stack(10);

stack_t *create_stack(int size)
{
    stack_t *stack = NULL;

    if((stack = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    if((stack->data = malloc(size * sizeof(int))) == NULL)
    {
        free(stack);
        exit(EXIT_FAILURE);
    }

    stack->ptr = 0;
    stack->size = size;

    return stack;
}

void stack_push(stack_t *stack, const int item)
{
    if(stack_is_full(stack))
    {
        printf("Stack full.");
        exit(EXIT_FAILURE);
    }

    stack->data[stack->ptr] = item;
    stack->ptr++;

    printf("stack->[%d]\n", item);
}

void stack_pop(stack_t *stack)
{
    if(stack_is_empty(stack))
    {
        printf("Stack empty.");
        exit(EXIT_FAILURE);
    } else {
        stack->ptr--;
        stack->data[stack->ptr];
    }
}

int stack_is_full(stack_t *stack)
{
    return stack->ptr == stack->size;
}

int stack_is_empty(stack_t *stack)
{
    return stack->ptr == 0;
}

int stack_peek(stack_t *stack)
{
    return stack->ptr;
}
