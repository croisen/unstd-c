#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_write(int fd, const char *buf, usize count) {
    return __syscall(__sys_linux_write, fd, buf, count);
}
