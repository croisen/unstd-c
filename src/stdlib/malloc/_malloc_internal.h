#ifndef _MALLOC_INTERNAL_H
#define _MALLOC_INTERNAL_H

#include "stddef.h"

struct __heap_chunk_t {
    size_t prev_size;
    size_t size;
    struct __heap_chunk_t *next;
};

struct __heap_data {
    struct __heap_chunk_t *freed;
    struct __heap_data *next;
    struct __heap_data *prev;
    size_t orig_size;
    size_t size;
};

extern struct __heap_data *libc_mem;

#endif /* _MALLOC_INTERNAL_H */
