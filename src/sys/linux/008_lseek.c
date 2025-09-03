#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_lseek(int fd, off_t offset, unsigned int origin) {
    return __syscall(__sys_linux_lseek, fd, offset, origin);
}
