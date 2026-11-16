#ifndef SHAREDLIB_H
#define SHAREDLIB_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linkedlist.h"

static FILE *error_log();
void create_process(pid_t);
void create_thread(pthread_t, void *(*)(void *), void *); 
void *write_data(void *);

#endif
