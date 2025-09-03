#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_epoll_wait_old(void) {
    return __syscall(__sys_linux_epoll_wait_old);
}
