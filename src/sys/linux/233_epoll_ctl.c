#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_epoll_ctl(int epfd, int op, int fd, struct epoll_event *event) {
    return __syscall(__sys_linux_epoll_ctl, epfd, op, fd, event);
}
