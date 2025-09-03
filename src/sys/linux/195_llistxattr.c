#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_llistxattr(const char *pathname, char *list, usize size) {
    return __syscall(__sys_linux_llistxattr, pathname, list, size);
}
