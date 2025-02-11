#include "../../misc/internal_syscall.h"
#include "sys/mman.h"
#include "syscall.h"

int mprotect(void *start, size_t len, int prot)
{
    return _syscall(SYS_mprotect, start, len, prot);
}
