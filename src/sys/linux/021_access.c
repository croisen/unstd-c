#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_access(const char *filename, int mode) {
    return __syscall(__sys_linux_access, filename, mode);
}
