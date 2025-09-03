#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_accept(int fd, struct sockaddr *upeer_sockaddr, int *upeer_addrlen) {
    return __syscall(__sys_linux_accept, fd, upeer_sockaddr, upeer_addrlen);
}
