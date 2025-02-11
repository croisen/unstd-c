#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include "sys/types.h"

int stat(const char *file, struct stat *buf);
int lstat(const char *filename, struct stat *buf);
int fstat(int fd, struct stat *buf);

#endif /* _SYS_STAT_H */
