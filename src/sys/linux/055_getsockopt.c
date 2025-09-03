#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getsockopt(int fd, int level, int optname, char *optval, int *optlen) {
    return __syscall(__sys_linux_getsockopt, fd, level, optname, optval, optlen);
}
