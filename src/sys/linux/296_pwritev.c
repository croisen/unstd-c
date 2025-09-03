#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pwritev(int fd, const struct iovec *vec, usize vlen, usize pos_l, usize pos_h) {
    return __syscall(__sys_linux_pwritev, fd, vec, vlen, pos_l, pos_h);
}
