#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sendfile(int out_fd, int in_fd, off_t *offset, usize count) {
    return __syscall(__sys_linux_sendfile, out_fd, in_fd, offset, count);
}
