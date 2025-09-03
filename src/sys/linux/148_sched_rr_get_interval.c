#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_rr_get_interval(pid_t pid, struct timespec *interval) {
    return __syscall(__sys_linux_sched_rr_get_interval, pid, interval);
}
