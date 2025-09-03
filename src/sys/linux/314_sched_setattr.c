#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_setattr(pid_t pid, struct sched_attr *attr, unsigned int flags) {
    return __syscall(__sys_linux_sched_setattr, pid, attr, flags);
}
