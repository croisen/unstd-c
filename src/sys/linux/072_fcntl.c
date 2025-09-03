#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fcntl(int fd, unsigned int cmd, usize arg) {
    return __syscall(__sys_linux_fcntl, fd, cmd, arg);
}
