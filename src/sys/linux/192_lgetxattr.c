#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_lgetxattr(const char *pathname, const char *name, void *value, usize size) {
    return __syscall(__sys_linux_lgetxattr, pathname, name, value, size);
}
