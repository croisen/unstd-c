#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_sigpending(sigset_t *set, usize sigsetsize) {
    return __syscall(__sys_linux_rt_sigpending, set, sigsetsize);
}
