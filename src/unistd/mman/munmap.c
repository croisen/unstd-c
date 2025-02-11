#include "../../misc/internal_syscall.h"
#include "sys/mman.h"
#include "syscall.h"

int munmap(void *addr, size_t len)
{
    return _syscall(SYS_munmap, addr, len);
}
