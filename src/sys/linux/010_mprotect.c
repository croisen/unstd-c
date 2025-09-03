#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mprotect(void *addr, usize len, usize prot) {
    return __syscall(__sys_linux_mprotect, addr, len, prot);
}
