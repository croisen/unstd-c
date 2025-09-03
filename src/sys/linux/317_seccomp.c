#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_seccomp(unsigned int op, unsigned int flags, const char *uargs) {
    return __syscall(__sys_linux_seccomp, op, flags, uargs);
}
