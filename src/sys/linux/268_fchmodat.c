#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fchmodat(int dfd, const char *filename, mode_t mode) {
    return __syscall(__sys_linux_fchmodat, dfd, filename, mode);
}
