#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fremovexattr(int fd, const char *name) {
    return __syscall(__sys_linux_fremovexattr, fd, name);
}
