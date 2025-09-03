#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_munmap(void *addr, usize len) {
    return __syscall(__sys_linux_munmap, addr, len);
}
