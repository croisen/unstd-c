#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pselect6(int n, fd_set *inp, fd_set *outp, fd_set *exp, struct timespec *tsp, void *sig) {
    return __syscall(__sys_linux_pselect6, n, inp, outp, exp, tsp, sig);
}
