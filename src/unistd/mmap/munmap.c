#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int munmap(void *addr, size_t len) { return _syscall(SYS_mmap, addr, len); }
