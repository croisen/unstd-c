#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_creat(const char *pathname, int mode) {
    return __syscall(__sys_linux_creat, pathname, mode);
}
