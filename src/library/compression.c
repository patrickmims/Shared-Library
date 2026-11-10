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
 *
 * deflateEnd(z_streamp stream)
 * All dynamically allocated datastructures from this stream are freed. 
 * This function discards any unprocessed input and does not flush any 
 * pending output.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define CHUNK_SIZE (128 * 1024)
#define LEVEL 6

z_stream z_init()
{
    z_stream stream;

    stream.avail_in = 0;
    stream.next_in = Z_NULL;
    stream.opaque = Z_NULL;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;

    return stream;
}

int pack()
{
    int flush, rc;

    FILE *src = NULL, *dest = NULL;

    unsigned char in[CHUNK_SIZE];
    unsigned char out[CHUNK_SIZE];
    unsigned items;

    puts("pack() - compression...");

    if((src = fopen("source.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    z_stream zs = z_init(); // <= Initialize reference to z_stream.

    if((rc = deflateInit(&zs, LEVEL)) != Z_OK)
        return rc;

    do // <= Compress to the end of the file.
    {
        // fread() reads n items of data, each bytes long, from the stream
        // pointed to by stream, storing them at the location given by ptr.
        zs.avail_in = fread(in, 1, CHUNK_SIZE, src);

        if(ferror(src))
        {
            (void)deflateEnd(&zs);
            return Z_ERRNO;
        }

        flush = feof(src) ? Z_FINISH : Z_NO_FLUSH;
        zs.next_in = in; // next input byte.
        
        // run deflate() on input until output buffer not full, finish
        // compression if all of source has been read in.

        do {
            zs.avail_out = CHUNK_SIZE;
            zs.next_out = out;

            rc = deflate(&zs, flush); // no bad return value 
            items = CHUNK_SIZE - zs.avail_out;

            if(fwrite(out, 1, items, dest) != items || ferror(dest))
            {
                (void)deflateEnd(&zs);
                return Z_ERRNO;
            }
        } while(zs.avail_out == 0);
    } while(flush != Z_FINISH);

    (void)deflateEnd(&zs);

    return Z_OK;
}





















