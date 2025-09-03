#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_readv(int fd, const struct iovec *vec, usize vlen) {
    return __syscall(__sys_linux_readv, fd, vec, vlen);
}
