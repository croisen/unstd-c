#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_setscheduler(pid_t pid, int policy, struct sched_param *param) {
    return __syscall(__sys_linux_sched_setscheduler, pid, policy, param);
}
