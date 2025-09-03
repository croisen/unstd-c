#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pipe(int *filedes) {
    return __syscall(__sys_linux_pipe, filedes);
}
