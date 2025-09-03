#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_wait4(pid_t upid, int *stat_addr, int options, struct rusage *ru) {
    return __syscall(__sys_linux_wait4, upid, stat_addr, options, ru);
}
