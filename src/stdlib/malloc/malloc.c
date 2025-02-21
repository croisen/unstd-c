#include "stdlib.h"
#include "sys/mman.h"

#include "_malloc_internal.h"

struct __heap_data *libc_mem = NULL;

void *malloc(size_t size)
{
    void *ret                = NULL;
    struct __heap_data **d   = &libc_mem;
    struct __heap_data *last = NULL;

    while (*d != NULL && (size + sizeof(struct __heap_chunk_t)) >= (*d)->size) {
        d = &(*d)->next;
        if ((*d)->next != NULL)
            last = (*d)->next;
    }

    if (*d == NULL) {
        if (size < (4096 - (sizeof(struct __heap_chunk_t) + sizeof(*d)))) {
            *d = mmap(
                NULL, 4096 + sizeof(*d), PROT_READ | PROT_WRITE,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
            );
            if (*d == MAP_FAILED)
                goto ret;

            (*d)->size      = 4096;
            (*d)->orig_size = 4096 + sizeof(**d);
        } else {
            *d = mmap(
                NULL, size + sizeof(struct __heap_chunk_t) + sizeof(*d),
                PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
            );
            if (*d == MAP_FAILED)
                goto ret;

            (*d)->size = size + sizeof(struct __heap_chunk_t);
            (*d)->orig_size =
                size + sizeof(**d) + sizeof(struct __heap_chunk_t);
        }

        (*d)->next  = NULL;
        (*d)->prev  = last;
        (*d)->freed = (struct __heap_chunk_t *)((*d) + 1);
    }

    struct __heap_chunk_t *c  = (*d)->freed;
    c->size                   = size;
    (*d)->size               -= (size + sizeof(*c));
    (*d)->freed = (struct __heap_chunk_t *)((char *)c + sizeof(*c) + size);
    (*d)->freed->prev_size = c->size;
    ret                    = c + 1;

ret:
    return ret;
}
