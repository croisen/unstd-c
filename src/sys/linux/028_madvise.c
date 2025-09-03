#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_madvise(void *addr, usize size, int advice) {
    return __syscall(__sys_linux_madvise, addr, size, advice);
}
