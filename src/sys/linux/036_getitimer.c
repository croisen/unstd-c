#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getitimer(int which, struct itimerval *value) {
    return __syscall(__sys_linux_getitimer, which, value);
}
