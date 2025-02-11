#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int fstat(int fd, struct stat *restrict buf) {
  return _syscall(SYS_fstat, fd, buf);
}
