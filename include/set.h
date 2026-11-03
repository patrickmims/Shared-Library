#ifndef SET_H
#define SET_H

void set_init(Set *,int (*)(const void *, const  void *), void (*)(void *));
int set_difference(Set *, const Set *, const Set *);
int set_insert(Set *, const void *);
int set_intersection(Set *, const Set *, const Set *);
int set_is_equal(const Set *, const Set *);
int set_is_member(const Set *, const  void *);
int set_is_subset(const Set *, const Set *);
int set_remove(Set *, void **);
int set_size(const Set *);
int set_union(Set *, const Set *, const Set *);
void set_destroy(Set *);

#endif
