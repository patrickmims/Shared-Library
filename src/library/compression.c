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

#define CHUNK_SIZE 16384

int pack(FILE *src, FILE *dest)
{
    int flush;
    int rc;

    unsigned char in[CHUNK_SIZE];
    unsigned char out[CHUNK_SIZE];
    unsigned items;

    // FILE *destination = NULL; 

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

            // fwrite(), writes n items of data, each size bytes long, 
            // to the stream pointed to by stream, obtaining them from the
            // location given by ptr.
            // fwrite(const void *ptr, size_t size, size_t nmemb, FILE *);
            //
            // FILE *, Pointer to the FILE object that identifies the 
            // stream where date will be written.
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

void *unpack(FILE *src) {}
























