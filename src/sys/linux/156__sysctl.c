#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux__sysctl(struct __sysctl_args *args) {
    return __syscall(__sys_linux__sysctl, args);
}
