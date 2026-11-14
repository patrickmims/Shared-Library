#include "sharedlibrary.h"

FILE *filePtr()
{
    FILE *ptr = NULL;

    if((ptr = fopen("data.bin", "wb")) = NULL)
        exit(EXIT_FAILURE);

    return ptr;
}

void *fwrite_data(struct Node *list)
{
    void *(*fp)() = filePtr;
    fwrite(list, sizeof(struct Node *), 1, fp)
}
