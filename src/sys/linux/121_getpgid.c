#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getpgid(pid_t pid) {
    return __syscall(__sys_linux_getpgid, pid);
}
