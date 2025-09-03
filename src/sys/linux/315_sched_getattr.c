#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_getattr(pid_t pid, struct sched_attr *attr, unsigned int size, unsigned int flags) {
    return __syscall(__sys_linux_sched_getattr, pid, attr, size, flags);
}
