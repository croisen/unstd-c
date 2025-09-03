#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_get_priority_max(int policy) {
    return __syscall(__sys_linux_sched_get_priority_max, policy);
}
