#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_clock_settime(const clockid_t which_clock, const struct timespec *tp) {
    return __syscall(__sys_linux_clock_settime, which_clock, tp);
}
