#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_umount2(const char *target, int flags) {
    return __syscall(__sys_linux_umount2, target, flags);
}
