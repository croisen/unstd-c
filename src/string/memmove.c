#include "string.h"

void *memmove(void *dst, const void *src, size_t n)
{
    char *d = dst;
    char *s = (char *)src;
    if (s + n >= d && d >= s )
    {
        d += n - 1;
        s += n - 1;
        while (n--)
            *d-- = *s--;
    }
    else
        while (n--)
            *d++ = *s++;

    return dst;
}
