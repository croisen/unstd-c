#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setpgid(pid_t pid, pid_t pgid) {
    return __syscall(__sys_linux_setpgid, pid, pgid);
}
