#include "stdlib.h"
#include "string.h"

#include "_malloc_internal.h"

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return malloc(size);

    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    struct __heap_data *d = find_heap(ptr);
    if (d == NULL)
        return NULL;

    struct __heap_chunk_t *c = (struct __heap_chunk_t *)ptr - 1;
    size_t orig_size = c->size;
    if (c->size >= size)
        return c + 1;

    while (merge_chunk_after2(d, c));
    if (c->size >= size)
    {
        trim_chunk(d, c, size);
        return c + 1;
    }

    void *p = malloc(size);
    if (p != NULL)
    {
        (void)memcpy(p, c + 1, orig_size);
        free(ptr);
    }

    return p;
}
