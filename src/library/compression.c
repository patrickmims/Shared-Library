#include "compression.h"

/* Stream Data Structures
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * z_stream stream => reference to z_stream
 * avail_in - number of bytes available at next_in.
 *  next_in - next input byte.
 *   opaque - private data object passed to zalloc and zfree.
 *   zalloc - used to allocate the internal state.
 *    zfree - used to free the internal state.
 *
 * Z_OK - 0, Z_FINISH - 4
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define CHUNK 16384

int pack(FILE *src)
{
    int flush;
    int rc;

    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    FILE *destination = NULL; 

    z_stream zs;

    zs.avail_in = 0;
    zs.next_in = Z_NULL;
    zs.opaque = Z_NULL;
    zs.zalloc = Z_NULL;
    zs.zfree = Z_NULL;

    // Initializes the internal stream state for compression.
    if((rc = deflateInit(&zs, Z_DEFAULT_COMPRESSION)) != Z_OK)
        return rc;

    // compress to end of file.
    do
    {
        zs.avail_in = fread(in, 1, CHUNK, src);
    } while(flush != Z_FINISH);

    (void)deflateEnd(&zs);

    return Z_OK;
}

void *unpack(FILE *src) {}
