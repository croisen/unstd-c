#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fchmod(int fd, mode_t mode) {
    return __syscall(__sys_linux_fchmod, fd, mode);
}
