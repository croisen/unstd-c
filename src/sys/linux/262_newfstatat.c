#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_newfstatat(int dfd, const char *filename, struct stat *statbuf, int flag) {
    return __syscall(__sys_linux_newfstatat, dfd, filename, statbuf, flag);
}
