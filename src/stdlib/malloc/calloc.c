#include "stdlib.h"
#include "string.h"

void *calloc(size_t nmemb, size_t size)
{
    void *p = malloc(nmemb * size);
    if (p != NULL)
        (void)memset(p, 0, size);

    return p;
}
