#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timerfd_gettime(int ufd, struct itimerspec *otmr) {
    return __syscall(__sys_linux_timerfd_gettime, ufd, otmr);
}
