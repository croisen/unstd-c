#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fstat(int fd, struct stat *statbuf) {
    return __syscall(__sys_linux_fstat, fd, statbuf);
}
