#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getpriority(int which, int who) {
    return __syscall(__sys_linux_getpriority, which, who);
}
