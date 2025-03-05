#include "stdlib.h"
#include "sys/mman.h"

#include "_malloc_internal.h"

struct __heap_data *libc_mem = NULL;

void *malloc(size_t size)
{
    void *ret                = NULL;
    struct __heap_data *d   = libc_mem;
    struct __heap_data *last = find_last_heap();
    size_t target_size = 
        (size < (4096 - (HEAP_CHUNK_SIZE + HEAP_DATA__SIZE)))
            ? 4096
            : size + HEAP_CHUNK_SIZE;

    while (d != NULL && (size + sizeof(struct __heap_chunk_t)) >= d->size) {
        if (d->next == NULL)
            last = d;

        d = d->next;
    }

    if (d == NULL)
    {
        if ((d = new_heap(target_size, last)) == NULL)
            return NULL;
    }
    else
    {
        merge_free_chunks(d);
    }

    struct __heap_chunk_t *c = find_free_chunk(d, size);
    if (c == NULL) {
        if ((d = new_heap(target_size, last)) == NULL)
            return NULL;
        else
            c = find_free_chunk(d, size);
    }

    trim_chunk(d, c, size);
    d->size               -= (c->size + sizeof(*c));
    c->freed               = false;
    ret                    = c + 1;
    return ret;
}
