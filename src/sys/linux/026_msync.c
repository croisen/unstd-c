#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_msync(void *addr, usize len, int flags) {
    return __syscall(__sys_linux_msync, addr, len, flags);
}
