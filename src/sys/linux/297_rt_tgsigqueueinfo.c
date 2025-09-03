#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *uinfo) {
    return __syscall(__sys_linux_rt_tgsigqueueinfo, tgid, pid, sig, uinfo);
}
