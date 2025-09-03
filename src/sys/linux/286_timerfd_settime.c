#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timerfd_settime(int ufd, int flags, const struct itimerspec *utmr, struct itimerspec *otmr) {
    return __syscall(__sys_linux_timerfd_settime, ufd, flags, utmr, otmr);
}
