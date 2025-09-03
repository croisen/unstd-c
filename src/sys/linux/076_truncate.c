#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_truncate(const char *path, long length) {
    return __syscall(__sys_linux_truncate, path, length);
}
