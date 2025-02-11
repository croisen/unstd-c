#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int poll(struct pollfd *ufds, unsigned int nfds, long timeout_msecs)
{
    return _syscall(SYS_poll, ufds, nfds, timeout_msecs);
}
