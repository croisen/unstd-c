#ifndef _MALLOC_INTERNAL_H
#define _MALLOC_INTERNAL_H

#include "stdbool.h"
#include "stddef.h"

struct __heap_chunk_t {
    size_t prev_size;
    size_t size;
    bool   freed;
    struct __heap_chunk_t *next;
};

struct __heap_data {
    struct __heap_data *next;
    struct __heap_data *prev;
    size_t orig_size;
    size_t size;
};

extern struct __heap_data *libc_mem;

#define HEAP_DATA__SIZE sizeof(struct __heap_data)
#define HEAP_CHUNK_SIZE sizeof(struct __heap_chunk_t)
#define IS_PTR_IN_HEAP(p, d)                                                   \
    ((char *)p > (char *)d && (char *)p < ((char *)d + d->orig_size))

struct __heap_data *new_heap(size_t target_size, struct __heap_data *last);
struct __heap_data *find_last_heap(void);

struct __heap_chunk_t *
prev_chunk(struct __heap_data *d, struct __heap_chunk_t *c);
struct __heap_chunk_t *
next_chunk(struct __heap_data *d, struct __heap_chunk_t *c);
struct __heap_chunk_t *find_free_chunk(struct __heap_data *d, size_t size);
void trim_chunk(struct __heap_data *d, struct __heap_chunk_t *c, size_t size);

bool merge_chunk_after(struct __heap_data *d, struct __heap_chunk_t *c);
void merge_free_chunks(struct __heap_data *d);

#endif /* _MALLOC_INTERNAL_H */
