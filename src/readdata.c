#include "sharedlibrary.h"
#include "linkedlist.h"

FILE *error_read()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("error.txt", "a")))

        return filePtr;
}

void *read_data(FILE *file, void *list)
{
    size_t rc;

    FILE *fp = NULL;

    if((fp = fopen(file, "rb")) == NULL)
        fprintf(error_read(), "Error: read_data");

}
