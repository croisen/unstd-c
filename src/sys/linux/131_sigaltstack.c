#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sigaltstack(const stack_t *uss, stack_t *uoss) {
    return __syscall(__sys_linux_sigaltstack, uss, uoss);
}
