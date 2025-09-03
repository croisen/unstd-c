#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_listen(int fd, int backlog) {
    return __syscall(__sys_linux_listen, fd, backlog);
}
