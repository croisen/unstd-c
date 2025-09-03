#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_chroot(const char *filename) {
    return __syscall(__sys_linux_chroot, filename);
}
