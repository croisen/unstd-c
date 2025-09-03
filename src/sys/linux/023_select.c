#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_select(int n, fd_set *inp, fd_set *outp, fd_set *exp, struct timeval *tvp) {
    return __syscall(__sys_linux_select, n, inp, outp, exp, tvp);
}
