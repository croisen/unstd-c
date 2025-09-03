#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_dup3(unsigned int oldfd, unsigned int newfd, int flags) {
    return __syscall(__sys_linux_dup3, oldfd, newfd, flags);
}
