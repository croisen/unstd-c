#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_arch_prctl(int code, usize *addr) {
    return __syscall(__sys_linux_arch_prctl, code, addr);
}
