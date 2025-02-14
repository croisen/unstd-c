#include "stdlib.h"
#include "sys/mman.h"

struct __heap_chunk_t {
    size_t size;
    struct __heap_chunk_t *prev;
    struct __heap_chunk_t *next;
    // payload
};

struct __heap_data {
    struct __heap_chunk_t *used;
    struct __heap_chunk_t *freed;
    struct __heap_data *next;
    size_t size;
};

struct __heap_data *libc_mem = NULL;

// __heap_data
//  freed: after the heap_data
//

void *malloc(size_t size)
{
    struct __heap_data *d = libc_mem;
    while (d != NULL && size >= d->size)
        d = d->next;

    if (d == NULL) {
        d = mmap(
            NULL, 4096 + sizeof(*d), PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
        );
        if (d == MAP_FAILED)
            return NULL;

        d->size  = 4096;
        d->next  = NULL;
        d->used  = NULL;
        d->freed = (void *)(d + 1);
    }

    void *ret                = NULL;
    struct __heap_chunk_t *c = d->freed;
    c->size                  = size;
    c->next        = (struct __heap_chunk_t *)((char *)c + sizeof(*c) + size);
    c->next->prev  = c;
    d->size       -= size + sizeof(*c);

    struct __heap_chunk_t **e = &d->used;
    while (*e != NULL)
        e = &(*e)->next;

    d->freed = c->next;
    *e       = c;
    ret      = c + 1;

    return ret;
}
