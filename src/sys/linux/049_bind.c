#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_bind(int fd, struct sockaddr *umyaddr, int addrlen) {
    return __syscall(__sys_linux_bind, fd, umyaddr, addrlen);
}
