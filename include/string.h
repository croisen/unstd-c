#ifndef _STRING_H
#define _STRING_H

#include "stddef.h"

void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *p, int c, size_t n);

size_t strlen(const char *s);

#endif /* _STRING_H */
