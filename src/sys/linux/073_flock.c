#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_flock(int fd, unsigned int cmd) {
    return __syscall(__sys_linux_flock, fd, cmd);
}
