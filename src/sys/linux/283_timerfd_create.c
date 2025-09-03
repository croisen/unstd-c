#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timerfd_create(int clockid, int flags) {
    return __syscall(__sys_linux_timerfd_create, clockid, flags);
}
