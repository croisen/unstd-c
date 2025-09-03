#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_sigprocmask(int how, sigset_t *nset, sigset_t *oset, usize sigsetsize) {
    return __syscall(__sys_linux_rt_sigprocmask, how, nset, oset, sigsetsize);
}
