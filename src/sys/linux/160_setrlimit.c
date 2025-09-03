#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setrlimit(unsigned int resource, struct rlimit *rlim) {
    return __syscall(__sys_linux_setrlimit, resource, rlim);
}
