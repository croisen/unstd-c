#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getrlimit(unsigned int resource, struct rlimit *rlim) {
    return __syscall(__sys_linux_getrlimit, resource, rlim);
}
