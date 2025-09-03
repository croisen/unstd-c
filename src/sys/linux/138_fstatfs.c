#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fstatfs(int fd, struct statfs *buf) {
    return __syscall(__sys_linux_fstatfs, fd, buf);
}
