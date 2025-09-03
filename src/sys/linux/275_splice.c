#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_splice(int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, usize len, unsigned int flags) {
    return __syscall(__sys_linux_splice, fd_in, off_in, fd_out, off_out, len, flags);
}
