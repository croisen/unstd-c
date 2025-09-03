#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sendmsg(int fd, struct msghdr *msg, unsigned flags) {
    return __syscall(__sys_linux_sendmsg, fd, msg, flags);
}
