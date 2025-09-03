#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fgetxattr(int fd, const char *name, void *value, usize size) {
    return __syscall(__sys_linux_fgetxattr, fd, name, value, size);
}
