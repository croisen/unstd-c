#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

#include <asm/mman.h>
#include <linux/mman.h>

#include "stddef.h"
#include "types.h"

#define MAP_FAILED (void *)-1

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off);
int munmap(void *addr, size_t len);
int mprotect(void *start, size_t len, int prot);

#endif /* _SYS_MMAN_H */
