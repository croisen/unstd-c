#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_set_mempolicy(int mode, usize *nmask, usize maxnode) {
    return __syscall(__sys_linux_set_mempolicy, mode, nmask, maxnode);
}
