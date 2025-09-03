#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_getscheduler(pid_t pid) {
    return __syscall(__sys_linux_sched_getscheduler, pid);
}
