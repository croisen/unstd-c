#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_stat(const char *filename, struct stat *statbuf) {
    return __syscall(__sys_linux_stat, filename, statbuf);
}
