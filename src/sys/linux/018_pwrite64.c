#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pwrite64(int fd, const char *buf, usize count, loff_t pos) {
    return __syscall(__sys_linux_pwrite64, fd, buf, count, pos);
}
