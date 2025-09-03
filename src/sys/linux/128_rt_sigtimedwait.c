#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_sigtimedwait(const sigset_t *uthese, siginfo_t *uinfo, const struct timespec *uts, usize sigsetsize) {
    return __syscall(__sys_linux_rt_sigtimedwait, uthese, uinfo, uts, sigsetsize);
}
