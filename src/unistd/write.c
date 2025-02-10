#include "syscall.h"
#include "unistd.h"

long write(unsigned int fd, const char *buf, long unsigned int count) {
  return syscall(1, fd, buf, count);
}
