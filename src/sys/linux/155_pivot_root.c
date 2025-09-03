#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pivot_root(const char *new_root, const char *put_old) {
    return __syscall(__sys_linux_pivot_root, new_root, put_old);
}
