#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setns(int fd, int nstype) {
    return __syscall(__sys_linux_setns, fd, nstype);
}
