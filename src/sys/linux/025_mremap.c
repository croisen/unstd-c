#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mremap(void *addr, usize old_len, usize new_len, usize flags, void *new_addr) {
    return __syscall(__sys_linux_mremap, addr, old_len, new_len, flags, new_addr);
}
