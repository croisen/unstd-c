#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_utimensat(int dfd, const char *filename, struct timespec *utimes, int flags) {
    return __syscall(__sys_linux_utimensat, dfd, filename, utimes, flags);
}
