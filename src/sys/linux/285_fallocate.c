#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fallocate(long fd, long mode, loff_t offset, loff_t len) {
    return __syscall(__sys_linux_fallocate, fd, mode, offset, len);
}
