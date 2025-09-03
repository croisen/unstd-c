#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mbind(usize start, usize len, usize mode, usize *nmask, usize maxnode, unsigned flags) {
    return __syscall(__sys_linux_mbind, start, len, mode, nmask, maxnode, flags);
}
