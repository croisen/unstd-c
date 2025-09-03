#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_read(int fd, char *buf, usize count) {
    return __syscall(__sys_linux_read, fd, buf, count);
}
