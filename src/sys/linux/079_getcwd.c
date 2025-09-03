#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getcwd(char *buf, usize size) {
    return __syscall(__sys_linux_getcwd, buf, size);
}
