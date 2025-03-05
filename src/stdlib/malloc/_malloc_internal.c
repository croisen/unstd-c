#include "sys/mman.h"

#include "stdbool.h"

#include "_malloc_internal.h"

struct __heap_data *new_heap(size_t target_size, struct __heap_data *last)
{
    struct __heap_data *d = mmap(
        NULL, target_size + HEAP_DATA__SIZE, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
    );
    if (d == MAP_FAILED)
        return NULL;

    d->size                  = target_size;
    d->orig_size             = target_size + HEAP_DATA__SIZE;
    d->next                  = NULL;
    d->prev                  = last;
    struct __heap_chunk_t *t = (struct __heap_chunk_t *)(d + 1);
    t->freed                 = true;
    t->size                  = target_size - HEAP_CHUNK_SIZE;
    t->prev_size             = 0;
    if (d->prev != NULL)
        d->prev->next = d;

    if (libc_mem == NULL)
        libc_mem = d;

    return d;
}

struct __heap_data *find_last_heap(void)
{
    if (libc_mem == NULL)
        return NULL;

    struct __heap_data *d = libc_mem;
    while (d->next != NULL)
        d = d->next;

    return d;
}

struct __heap_chunk_t *
prev_chunk(struct __heap_data *d, struct __heap_chunk_t *c)
{
    if (d == NULL)
        return NULL;

    if (c == NULL || c->prev_size == 0)
        return NULL;

    struct __heap_chunk_t *prev=
        (struct __heap_chunk_t *)((char *)c - c->prev_size - HEAP_CHUNK_SIZE);
    return (IS_PTR_IN_HEAP(prev, d)) ? prev : NULL;
}

struct __heap_chunk_t *
next_chunk(struct __heap_data *d, struct __heap_chunk_t *c)
{
    if (d == NULL)
        return NULL;

    if (c == NULL)
        return (struct __heap_chunk_t *)(d + 1);

    struct __heap_chunk_t *next =
        (struct __heap_chunk_t *)((char *)c + c->size + HEAP_CHUNK_SIZE);
    return (IS_PTR_IN_HEAP(next, d)) ? next : NULL;
}

struct __heap_chunk_t *find_free_chunk(struct __heap_data *d, size_t size)
{
    struct __heap_chunk_t *r = NULL;
    while ((r = next_chunk(d, r)) != NULL)
        if (r->freed && r->size >= size)
            break;

    return r;
}

void trim_chunk(struct __heap_data *d, struct __heap_chunk_t *c, size_t size)
{
    if (c->size - HEAP_CHUNK_SIZE == 0 || c->size < c->size - HEAP_CHUNK_SIZE)
        return;

    struct __heap_chunk_t *next = next_chunk(d, c);
    struct __heap_chunk_t *new  =
        (struct __heap_chunk_t *)((char *) c + size + HEAP_CHUNK_SIZE);
    if (next != NULL)
        next->prev_size = c->size - size - HEAP_CHUNK_SIZE;

    if (IS_PTR_IN_HEAP(new, d)) {
        new->size      = c->size - size - HEAP_CHUNK_SIZE;
        new->freed     = true;
        new->prev_size = size;
    }

    c->size = size;
}

bool merge_chunk_after(struct __heap_data *d, struct __heap_chunk_t *c)
{
    if (!c->freed)
        return false;

    struct __heap_chunk_t *next = next_chunk(d, c);
    if (next == NULL || !next->freed)
        return false;

    struct __heap_chunk_t *nextnext = next_chunk(d, c);
    if (nextnext != NULL)
        nextnext->prev_size = c->size + next->size + HEAP_CHUNK_SIZE;

    c->size = c->size + next->size + HEAP_CHUNK_SIZE;
    return true;
}

void merge_free_chunks(struct __heap_data *d)
{
    struct __heap_chunk_t *c = next_chunk(d, NULL);
    while (c != NULL)
        if (merge_chunk_after(d, c))
            continue;
        else
            c = next_chunk(d, c);
}
