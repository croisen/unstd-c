#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_keyctl(int option, usize arg2, usize arg3, usize arg4, usize arg5) {
    return __syscall(__sys_linux_keyctl, option, arg2, arg3, arg4, arg5);
}
