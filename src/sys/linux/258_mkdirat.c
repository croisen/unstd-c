#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mkdirat(int dfd, const char *pathname, int mode) {
    return __syscall(__sys_linux_mkdirat, dfd, pathname, mode);
}
