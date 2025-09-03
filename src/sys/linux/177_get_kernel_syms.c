#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_get_kernel_syms(void) {
    return __syscall(__sys_linux_get_kernel_syms);
}
