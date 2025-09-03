#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_statfs(const char *pathname, struct statfs *buf) {
    return __syscall(__sys_linux_statfs, pathname, buf);
}
