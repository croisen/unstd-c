#ifndef _UNISTD_H
#define _UNISTD_H

void _exit(int status);
long write(unsigned int fd, const char *buf, long unsigned int count);

long syscall(long no, ...);

#endif /* _UNISTD_H */
