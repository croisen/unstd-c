#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_futimesat(int dfd, const char *filename, struct timeval *utimes) {
    return __syscall(__sys_linux_futimesat, dfd, filename, utimes);
}
