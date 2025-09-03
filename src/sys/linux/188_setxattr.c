#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setxattr(const char *pathname, const char *name, const void *value, usize size, int flags) {
    return __syscall(__sys_linux_setxattr, pathname, name, value, size, flags);
}
