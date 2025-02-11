#include "../../misc/internal_syscall.h"
#include "sys/mman.h"
#include "syscall.h"

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off)
{
    return (void *)_syscall(SYS_mmap, addr, len, prot, flags, fd, off);
}
