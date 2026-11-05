#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    void *data;
    struct Node *next;
} node_t;

typedef struct Set 
{
    int size;
    node_t *head;
    node_t *tail;
//    int (*match)(const void *key1, const void *key2);
//    void (*destroy)(void *data);
} set_t;

// void list_init(list_t *, void (*)(void *));
// void set_init(set_t *, int (*)(const void *, const  void *), void (*)(void *));
// void set_init(set_t *, void (*)(void *));
void set_init(set_t *);
int set_difference(set_t *, const set_t *, const set_t *);
int set_insert(set_t *, const void *);
int set_intersection(set_t *, const set_t *, const set_t *);
int set_is_equal(const set_t *, const set_t *);
int set_is_member(const set_t *, const  void *);
int set_is_subset(const set_t *, const set_t *);
int set_remove(set_t *, void **);
int set_size(const set_t *);
int set_union(set_t *, const set_t *, const set_t *);
void set_destroy(set_t *);

#endif
