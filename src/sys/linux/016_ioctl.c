#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ioctl(int fd, unsigned int cmd, usize arg) {
    return __syscall(__sys_linux_ioctl, fd, cmd, arg);
}
