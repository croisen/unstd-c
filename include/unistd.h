#ifndef UNISTD_H
#define UNISTD_H

void _exit(int status);
long write(unsigned int fd, const char *buf, long unsigned int count);

#endif /* UNISTD_H */
