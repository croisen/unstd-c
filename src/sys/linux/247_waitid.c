#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_waitid(int which, pid_t upid, struct siginfo *infop, int options, struct rusage *ru) {
    return __syscall(__sys_linux_waitid, which, upid, infop, options, ru);
}
