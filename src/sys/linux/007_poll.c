#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_poll(struct pollfd *ufds, unsigned int nfds, long timeout_msecs) {
    return __syscall(__sys_linux_poll, ufds, nfds, timeout_msecs);
}
