#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_prlimit64(pid_t pid, unsigned int resource, const struct rlimit64 *new_rlim, struct rlimit64 *old_rlim) {
    return __syscall(__sys_linux_prlimit64, pid, resource, new_rlim, old_rlim);
}
