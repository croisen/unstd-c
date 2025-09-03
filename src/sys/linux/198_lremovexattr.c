#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_lremovexattr(const char *pathname, const char *name) {
    return __syscall(__sys_linux_lremovexattr, pathname, name);
}
