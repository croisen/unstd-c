#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fadvise64(int fd, loff_t offset, usize len, int advice) {
    return __syscall(__sys_linux_fadvise64, fd, offset, len, advice);
}
