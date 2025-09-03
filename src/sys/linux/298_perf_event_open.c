#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_perf_event_open(struct perf_event_attr *attr_uptr, pid_t pid, int cpu, int group_fd, usize flags) {
    return __syscall(__sys_linux_perf_event_open, attr_uptr, pid, cpu, group_fd, flags);
}
