#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sendmmsg(int fd, struct mmsghdr *mmsg, unsigned int vlen, unsigned int flags) {
    return __syscall(__sys_linux_sendmmsg, fd, mmsg, vlen, flags);
}
