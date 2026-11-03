#include "set.h"

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

void list_init(list_t *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    puts("set has been initialized...");

    return;
}

void set_init(set_t *set,
        int (*match)(const void *key1, const void *key2), 
        void (*destroy)(void *data))
{
    list_init(set, destroy);
    set->match = match;
}
