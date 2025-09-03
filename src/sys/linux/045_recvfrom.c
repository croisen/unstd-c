#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_recvfrom(int fd, void *ubuf, usize size, unsigned flags, struct sockaddr *addr, int *addr_len) {
    return __syscall(__sys_linux_recvfrom, fd, ubuf, size, flags, addr, addr_len);
}
