#include "string.h"

void *memset(void *p, int c, size_t n)
{
    char *d = p;
    while (n--)
        *d++ = (char)c;

    return p;
}
