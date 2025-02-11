#ifndef _STDDEF_H
#define _STDDEF_H

typedef unsigned long size_t;
typedef long ssize_t;
typedef long wchar_t;

typedef size_t ptrdiff_t;

#define NULL (void *)0
#define offsetof(type, mem) __builtin_offsetof(type, mem)

#endif /* _STDDEF_H */
