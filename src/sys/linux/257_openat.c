#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_openat(int dfd, const char *filename, int flags, int mode) {
    return __syscall(__sys_linux_openat, dfd, filename, flags, mode);
}
