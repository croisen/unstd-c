#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mknod(const char *filename, mode_t mode, unsigned dev) {
    return __syscall(__sys_linux_mknod, filename, mode, dev);
}
