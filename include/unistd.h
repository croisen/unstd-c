#ifndef _UNISTD_H
#define _UNISTD_H

#include "stddef.h"

#include "sys/types.h"

void _exit(int status);
ssize_t read(int fd, char *buf, size_t count);
ssize_t write(int fd, const char *buf, size_t count);
int open(const char *filename, int flags, int mode);
ssize_t close(int fd);

int poll(struct pollfd *ufds, unsigned int nfds, long timeout_msecs);

off_t lseek(int fd, off_t offset, unsigned int origin);

void *sbrk(off_t increment)
    __attribute__((deprecated("I don't know how this works")));
int brk(void *addr) __attribute__((deprecated("I don't know how this works")));

long syscall(long no, ...);

#endif /* _UNISTD_H */
