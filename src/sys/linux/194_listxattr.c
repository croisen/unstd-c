#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_listxattr(const char *pathname, char *list, usize size) {
    return __syscall(__sys_linux_listxattr, pathname, list, size);
}
