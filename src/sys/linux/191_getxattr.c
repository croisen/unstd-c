#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getxattr(const char *pathname, const char *name, void *value, usize size) {
    return __syscall(__sys_linux_getxattr, pathname, name, value, size);
}
