#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_sigaction(int sig, const struct sigaction *act, struct sigaction *oact,usize sigsetsize) {
    return __syscall(__sys_linux_rt_sigaction, sig, act, sigsetsize);
}
