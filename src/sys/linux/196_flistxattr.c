#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_flistxattr(int fd, char *list, usize size) {
    return __syscall(__sys_linux_flistxattr, fd, list, size);
}
