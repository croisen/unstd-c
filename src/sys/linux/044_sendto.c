#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sendto(int fd, void *buff, usize len, unsigned flags, struct sockaddr *addr, int addr_len) {
    return __syscall(__sys_linux_sendto, fd, buff, len, flags, addr, addr_len);
}
