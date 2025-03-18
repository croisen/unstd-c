#include "string.h"

void *memcpy(void *dst, const void *src, size_t n)
{
    char *d = dst;
    char *s = (char *)src;
    while (n--)
        *d++ = *s++;

    return dst;
}
