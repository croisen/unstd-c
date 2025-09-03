#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_futex(u32 *uaddr, int op, u32 val, struct timespec *utime, u32 *uaddr2, u32 val3) {
    return __syscall(__sys_linux_futex, uaddr, op, val, utime, uaddr2, val3);
}
