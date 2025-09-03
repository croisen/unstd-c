#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_vmsplice(int fd, const struct iovec *iov, usize nr_segs, unsigned int flags) {
    return __syscall(__sys_linux_vmsplice, fd, iov, nr_segs, flags);
}
