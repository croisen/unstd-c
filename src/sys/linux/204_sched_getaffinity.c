#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sched_getaffinity(pid_t pid, unsigned int len, usize *user_mask_ptr) {
    return __syscall(__sys_linux_sched_getaffinity, pid, len, user_mask_ptr);
}
