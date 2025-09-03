#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_epoll_create(int size) {
    return __syscall(__sys_linux_epoll_create, size);
}
