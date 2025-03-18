#include "string.h"

size_t strlen(const char *s)
{
    const char *d;
    for (d = s; *d != 0; d++);
    return d - s;
}
