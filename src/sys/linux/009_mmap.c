#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mmap(void *addr, usize len, usize prot, usize flags, int fd, usize off) {
    return __syscall(__sys_linux_mmap, addr, len, prot, flags, fd, off);
}
