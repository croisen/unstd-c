#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ioprio_set(int which, int who, int ioprio) {
    return __syscall(__sys_linux_ioprio_set, which, who, ioprio);
}
