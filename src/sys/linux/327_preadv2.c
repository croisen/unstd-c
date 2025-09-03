#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_preadv2(int fd, const struct iovec *vec, usize vlen, usize pos_l, usize pos_h, int flags) {
    return __syscall(__sys_linux_preadv2, fd, vec, vlen, pos_l, pos_h, flags);
}
