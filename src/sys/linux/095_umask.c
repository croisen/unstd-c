#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_umask(int mask) {
    return __syscall(__sys_linux_umask, mask);
}
