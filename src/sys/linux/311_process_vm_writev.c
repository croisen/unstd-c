#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_process_vm_writev(pid_t pid, const struct iovec *lvec, usize liovcnt, const struct iovec *rvec, usize riovcnt, usize flags) {
    return __syscall(__sys_linux_process_vm_writev, pid, lvec, liovcnt, rvec, riovcnt, flags);
}
