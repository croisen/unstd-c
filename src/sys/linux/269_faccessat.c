#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_faccessat(int dfd, const char *filename, int mode) {
    return __syscall(__sys_linux_faccessat, dfd, filename, mode);
}
