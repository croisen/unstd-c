#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_shutdown(int fd, int how) {
    return __syscall(__sys_linux_shutdown, fd, how);
}
