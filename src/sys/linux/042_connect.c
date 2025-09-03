#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_connect(int fd, struct sockaddr *uservaddr, int addrlen) {
    return __syscall(__sys_linux_connect, fd, uservaddr, addrlen);
}
