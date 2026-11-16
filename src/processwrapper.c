#include "sharedlibrary.h"
#include "linkedlist.h"

static FILE *error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("process_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);
    
    return filePtr;
}

void create_process(pid_t pid)
{
    pthread_t thread;

    struct Node l;
    void *head = &l;

    head = (struct Node *)new_node();

    list_insert(head, 400);
    void *(*fn)() = write_data;

    switch(pid = fork())
    {
        case -1: 
            fprintf(error_log(), "Error: creating process...");
            break;
        case 0: 
            create_thread(thread, fn, head); // call thread.
            break;
        default: 
            puts("actions...");
    }
}
