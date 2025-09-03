#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ftruncate(int fd, usize length) {
    return __syscall(__sys_linux_ftruncate, fd, length);
}
