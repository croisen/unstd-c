#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int brk(void *addr) { return _syscall(SYS_brk, addr); }
