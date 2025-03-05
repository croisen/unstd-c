#include "stdlib.h"
#include "sys/mman.h"
#include "unistd.h"

#include "_malloc_internal.h"

void free(void *ptr)
{
    if (ptr == NULL)
        return;

    struct __heap_data *d = libc_mem;
    while (d != NULL) {
        if (IS_PTR_IN_HEAP(ptr, d))
            break;

        d = d->next;
    }

    if (d == NULL) {
        write(1, "free(): Invalid Pointer!\n", 25);
        exit(1);
    }

    struct __heap_chunk_t *f = ((struct __heap_chunk_t *)ptr) - 1;
    d->size                 += (f->size + HEAP_CHUNK_SIZE);
    if (d->size == (d->orig_size - HEAP_DATA__SIZE)) {
        if (d->prev == NULL)
            libc_mem = d->next;
        else
            d->prev->next = d->next;

        if (d->next != NULL)
            d->next->prev = d->prev;

        munmap(d, d->orig_size);
    }
}
