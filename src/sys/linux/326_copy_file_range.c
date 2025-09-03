#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_copy_file_range(int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, usize len, unsigned int flags) {
    return __syscall(__sys_linux_copy_file_range, fd_in, off_in, fd_out, off_out, len, flags);
}
