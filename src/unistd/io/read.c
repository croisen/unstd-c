#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

ssize_t read(int fd, char *buf, size_t count) {
  return _syscall(SYS_read, fd, buf, count);
}
