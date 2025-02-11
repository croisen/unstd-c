#include "../misc/internal_syscall.h"
#include "unistd.h"

long write(unsigned int fd, const char *buf, long unsigned int count) {
  return _syscall(1, fd, buf, count);
}
