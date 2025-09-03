#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_accept4(int fd, struct sockaddr *upeer_sockaddr, int *upeer_addrlen, int flags) {
    return __syscall(__sys_linux_accept4, fd, upeer_sockaddr, upeer_addrlen, flags);
}
