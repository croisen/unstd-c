#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sync_file_range(long fd, loff_t offset, loff_t bytes, long flags) {
    return __syscall(__sys_linux_sync_file_range, fd, offset, bytes, flags);
}
