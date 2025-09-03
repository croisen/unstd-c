#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pipe2(int *filedes, int flags) {
    return __syscall(__sys_linux_pipe2, filedes, flags);
}
