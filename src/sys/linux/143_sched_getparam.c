#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_getparam(pid_t pid, struct sched_param *param) {
    return __syscall(__sys_linux_sched_getparam, pid, param);
}
