#ifndef _UNISTD_H
#define _UNISTD_H

#include "stddef.h"

#include <sys/stat.h>
#include <sys/types.h>

typedef struct pollfd pollfd;

void _exit(int status);
ssize_t read(int fd, char *buf, size_t count);
ssize_t write(int fd, const char *buf, size_t count);
int open(const char *filename, int flags, int mode);
ssize_t close(int fd);

int poll(struct pollfd *ufds, unsigned int nfds, long timeout_msecs);

off_t lseek(int fd, off_t offset, unsigned int origin);

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off);
int munmap(void *addr, size_t len);

int brk(void *addr);

long syscall(long no, ...);

#endif /* _UNISTD_H */
