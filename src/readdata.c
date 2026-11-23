#include "sharedlibrary.h"
#include "linkedlist.h"

FILE *error_read()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("error.txt", "a")))

        return filePtr;
}

void *read_data(void *list)
{
    size_t rc;
    list = (struct Node *)list;

    FILE *fp = NULL;

    if((fp = fopen("data.bin", "rb")) == NULL)
        fprintf(error_read(), "Error: read_data");

    // something is nott working...
    /*
    while(fread(list, sizeof(void *), 1, fp)) 
    {
        printf("freading => %d\n", list->data);
    }
    */
}
