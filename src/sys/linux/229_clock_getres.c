#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_clock_getres(const clockid_t which_clock, struct timespec *tp) {
    return __syscall(__sys_linux_clock_getres, which_clock, tp);
}
