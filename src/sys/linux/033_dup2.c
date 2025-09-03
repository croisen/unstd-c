#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_dup2(unsigned int oldfd, unsigned int newfd) {
    return __syscall(__sys_linux_dup2, oldfd, newfd);
}
