#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fsetxattr(int fd, const char *name, const void *value, usize size, int flags) {
    return __syscall(__sys_linux_fsetxattr, fd, name, value, size, flags);
}
