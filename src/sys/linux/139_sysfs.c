#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sysfs(int option, usize arg1, usize arg2) {
    return __syscall(__sys_linux_sysfs, option, arg1, arg2);
}
