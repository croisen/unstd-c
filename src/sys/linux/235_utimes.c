#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_utimes(char *filename, struct timeval *utimes) {
    return __syscall(__sys_linux_utimes, filename, utimes);
}
