#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getpeername(int fd, struct sockaddr *usockaddr, int *usockaddr_len) {
    return __syscall(__sys_linux_getpeername, fd, usockaddr, usockaddr_len);
}
