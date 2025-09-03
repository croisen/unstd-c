#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_recvmsg(int fd, struct msghdr *msg, unsigned int flags) {
    return __syscall(__sys_linux_recvmsg, fd, msg, flags);
}
