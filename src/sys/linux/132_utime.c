#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_utime(char *filename, struct utimbuf *times) {
    return __syscall(__sys_linux_utime, filename, times);
}
