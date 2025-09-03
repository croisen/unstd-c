#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_gettimeofday(struct timeval *tv, struct timezone *tz) {
    return __syscall(__sys_linux_gettimeofday, tv, tz);
}
