#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_settimeofday(struct timeval *tv, struct timezone *tz) {
    return __syscall(__sys_linux_settimeofday, tv, tz);
}
