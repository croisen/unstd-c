#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_sigsuspend(sigset_t *unewset, usize sigsetsize) {
    return __syscall(__sys_linux_rt_sigsuspend, unewset, sigsetsize);
}
