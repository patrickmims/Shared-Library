#include "set.h"
#include <stdlib.h>

/* * 
 * Set Interface
 * November 3, 2026
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * 
 * The set_init operation initializes a set so that it can be used in other
 * operations. Since a set is a linked list, list_init is called to
 * initialize it. The match member is set to match by hand because this
 * member is not used by linked list and is therefore not  set by list_init. * The runtime complexity of set_init is the same as list_init, of O(1).
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
void list_init(list_t *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    puts("set has been initialized...");

    return;
}
*/

// try this example: github.com/barrust/set

void *memory()
{
    void *memory = NULL;

    if((memory = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return memory;
}

void set_init(set_t *set)
{
    set->size = 0;
    set->head = NULL;
    set->tail = NULL;
    // set->destroy = destroy;

    puts("set has been initialized...");
}

void set_destroy(set_t *set)
{
    void *data = NULL; 

    /*
    while(set_size(set) > 0) 
    {
        if(list_rem_next(set, NULL, (void **)&data) == 0 && list->destroy != NULL)
        {
            list->destroy(data);
        }
    }
    memset(set, 0, sizeof(set_t))
    */
}
