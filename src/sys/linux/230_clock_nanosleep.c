#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_clock_nanosleep(const clockid_t which_clock, int flags, const struct timespec *rqtp, struct timespec *rmtp) {
    return __syscall(__sys_linux_clock_nanosleep, which_clock, flags, rqtp, rmtp);
}
