#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_dup(unsigned int fildes) {
    return __syscall(__sys_linux_dup, fildes);
}
