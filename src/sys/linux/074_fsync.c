#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fsync(int fd) {
    return __syscall(__sys_linux_fsync, fd);
}
