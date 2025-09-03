#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ppoll(struct pollfd *ufds, unsigned int nfds, struct timespec *tsp, const sigset_t *sigmask, usize sigsetsize) {
    return __syscall(__sys_linux_ppoll, ufds, nfds, tsp, sigmask, sigsetsize);
}
