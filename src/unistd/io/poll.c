#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

struct pollfd {
  int fd;
  short events;
  short revents;
};

int poll(struct pollfd *ufds, unsigned int nfds, long timeout_msecs) {
  return _syscall(SYS_poll, ufds, nfds, timeout_msecs);
}
