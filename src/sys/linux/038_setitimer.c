#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setitimer(int which, struct itimerval *value, struct itimerval *ovalue) {
    return __syscall(__sys_linux_setitimer, which, value, ovalue);
}
