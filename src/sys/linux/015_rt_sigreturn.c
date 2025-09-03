#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rt_sigreturn(usize __unused) {
    return __syscall(__sys_linux_rt_sigreturn, __unused);
}
