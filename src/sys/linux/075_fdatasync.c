#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fdatasync(int fd) {
    return __syscall(__sys_linux_fdatasync, fd);
}
