#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_afs_syscall(void) {
    return __syscall(__sys_linux_afs_syscall);
}
