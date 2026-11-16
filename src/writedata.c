#include "sharedlibrary.h"

void *filePtr()
{
    FILE *ptr = NULL;

    if((ptr = fopen("data.bin", "wb")) == NULL)
        exit(EXIT_FAILURE);

    return ptr;
}

void *write_data(void *list)
{
    list = (struct Node *)list;
    int i;

    for(int i = 0; i < 20; i++)
    {
        list_insert(&list, (100 * i));
    }

    // function pointer
    void *(*fp)() = filePtr;

    // fwrite(&list, sizeof(struct Node *), 1, (FILE *)fp);
    fwrite(&list, sizeof(struct Node *), 1, filePtr());
}

/*
   I need to cast the void pointer, that doesn't want to be made a function ptr.
   In other words, we can't do this: 

   void *(*fp)() = (FILE *)filePtr or FILE *filePtr() { ... } 
*/
