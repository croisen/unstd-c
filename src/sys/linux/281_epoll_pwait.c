#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask, usize sigsetsize) {
    return __syscall(__sys_linux_epoll_pwait, epfd, events, maxevents, timeout, sigmask, sigsetsize);
}
