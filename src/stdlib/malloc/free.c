#include "stdlib.h"
#include "sys/mman.h"
#include "unistd.h"

#include "_malloc_internal.h"

void free(void *ptr)
{
    struct __heap_data *d = libc_mem;
    while (d != NULL) {
        if (ptr > (void *)d && ptr < ((void *)d + d->size + sizeof(*d)))
            break;

        d = d->next;
    }

    if (d == NULL) {
        write(1, "free(): Invalid Pointer!\n", 25);
        exit(1);
    }

    struct __heap_chunk_t *c = d->freed;
    if (c == NULL) {
        d->freed = (struct __heap_chunk_t *)ptr - 1;
        goto ret;
    }

    while (1) {
        if (c->next == NULL)
            break;

        c = c->next;
    }

    struct __heap_chunk_t *f = ((struct __heap_chunk_t *)ptr) - 1;
    c->next                  = f;

ret:
    d->size += (f->size + sizeof(*c));
    if (d->size == (d->orig_size - sizeof(*d))) {
        if (d->prev == NULL)
            libc_mem = d->next;
        else
            d->prev->next = NULL;

        munmap(d, d->orig_size);
    }
}
