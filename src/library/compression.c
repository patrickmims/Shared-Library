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

#define CHUNK_SIZE 4 
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

int pack(FILE *src, FILE *dest)
{
    int flush, rc;

    unsigned char input[CHUNK_SIZE], output[CHUNK_SIZE];
    unsigned items;

    z_stream zs = z_init(); // <= Initialize reference to z_stream.

    if((rc = deflateInit(&zs, LEVEL)) != Z_OK)
        return rc;

    printf("rc => %d\n", rc);

    do // <= Compress to the end of the file.
    {
        // fread() reads n items of data, each bytes long, from the stream
        // pointed to by stream, storing them at the location given by ptr.
        puts("debug 1"); 
        // zs.avail_in = fread(input, 1, CHUNK_SIZE, src);
        zs.avail_in = fread(input, sizeof(*input), CHUNK_SIZE, src);

        puts("debug 2"); 

        if(ferror(src)) // <= check if a write error occurred.
        {
            puts("Error: Write error occurred.");
            (void)deflateEnd(&zs);
            return Z_ERRNO;
        }

        puts("debug 3"); 

        flush = feof(src) ? Z_FINISH : Z_NO_FLUSH;
        puts("debug 4"); 
        zs.next_in = input; // next input byte.
        puts("debug 5"); 

        // Run deflate() on input until output buffer not full. 
        // Finish compression if all of source has been read in.

        do {
            puts("debug 6"); 
            zs.avail_out = CHUNK_SIZE;
            zs.next_out = output;

            rc = deflate(&zs, flush); // no bad return value 
                                      //
            items = CHUNK_SIZE - zs.avail_out;

            if(fwrite(output, 1, items, dest) != items || ferror(dest))
            {
                (void)deflateEnd(&zs);
                return Z_ERRNO;
            }
        } while(zs.avail_out == 0);
    } while(flush != Z_FINISH);

    puts("debug 7"); 
    (void)deflateEnd(&zs);
    fclose(src);
    fclose(dest);

    return Z_OK;
}





















