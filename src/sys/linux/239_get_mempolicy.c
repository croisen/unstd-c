#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_get_mempolicy(int *policy, usize *nmask, usize maxnode, usize addr, usize flags) {
    return __syscall(__sys_linux_get_mempolicy, policy, nmask, maxnode, addr, flags);
}
