#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_open(const char *filename, int flags, int mode) {
    return __syscall(__sys_linux_open, filename, flags, mode);
}
