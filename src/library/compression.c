#include "compression.h"

/* Stream Data Structures
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * z_stream stream => reference to z_stream
 * avail_in - Number of bytes available at next_in.
 *  next_in - Next input byte.
 *   opaque - Private data object passed to zalloc and zfree.
 *   zalloc - Used to allocate the internal state.
 *    zfree - Used to free the internal state.
 *
 * Z_OK - 0, Z_FINISH - 4
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define CHUNK_SIZE 16384

int pack(FILE *src)
{
    int flush;
    int rc;

    unsigned char in[CHUNK_SIZE];
    unsigned char out[CHUNK_SIZE];

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

    // Compress to the end of the file.
    do
    {
        zs.avail_in = fread(in, 1, CHUNK_SIZE, src);
    } while(flush != Z_FINISH);

    (void)deflateEnd(&zs);

    return Z_OK;
}

void *unpack(FILE *src) {}
