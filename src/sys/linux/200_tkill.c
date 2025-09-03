#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_tkill(pid_t pid, int sig) {
    return __syscall(__sys_linux_tkill, pid, sig);
}
