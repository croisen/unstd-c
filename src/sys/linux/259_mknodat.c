#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mknodat(int dfd, const char *filename, int mode, unsigned dev) {
    return __syscall(__sys_linux_mknodat, dfd, filename, mode, dev);
}
