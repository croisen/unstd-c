#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_yield(void) {
    return __syscall(__sys_linux_sched_yield);
}
