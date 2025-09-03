#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pread64(int fd, char *buf, usize count, loff_t pos) {
    return __syscall(__sys_linux_pread64, fd, buf, count, pos);
}
