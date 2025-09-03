#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_finit_module(int fd, const char *uargs, int flags) {
    return __syscall(__sys_linux_finit_module, fd, uargs, flags);
}
