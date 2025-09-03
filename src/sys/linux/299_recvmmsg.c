#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_recvmmsg(int fd, struct msghdr *mmsg, unsigned int vlen, unsigned int flags, struct timespec *timeout) {
    return __syscall(__sys_linux_recvmmsg, fd, mmsg, vlen, flags, timeout);
}
