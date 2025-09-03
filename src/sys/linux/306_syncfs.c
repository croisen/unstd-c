#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_syncfs(int fd) {
    return __syscall(__sys_linux_syncfs, fd);
}
