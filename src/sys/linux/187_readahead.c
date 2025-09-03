#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_readahead(int fd, loff_t offset, usize count) {
    return __syscall(__sys_linux_readahead, fd, offset, count);
}
