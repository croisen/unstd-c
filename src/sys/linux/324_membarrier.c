#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_membarrier(int cmd, int flags) {
    return __syscall(__sys_linux_membarrier, cmd, flags);
}
