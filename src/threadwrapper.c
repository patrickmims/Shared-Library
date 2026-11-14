#include "sharedlibrary.h"

void create_thread(pthread_t thread, void *(*fn)(void *), void *arg)
{
    void *result;

    if (pthread_create(&thread, NULL, fn, arg) != 0)
        fprintf(stderr, "Error: pthread_create()");

    int s = pthread_join(thread, &result); // 1. wait for the thread to finish.

    printf("create_thread() - [ %d ] \n", s);
}
