#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ioprio_get(int which, int who) {
    return __syscall(__sys_linux_ioprio_get, which, who);
}
