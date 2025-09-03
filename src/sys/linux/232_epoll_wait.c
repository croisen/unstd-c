#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout) {
    return __syscall(__sys_linux_epoll_wait, epfd, events, maxevents, timeout);
}
