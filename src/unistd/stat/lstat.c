#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int lstat(const char *restrict filename, struct stat *restrict buf) {
  return _syscall(SYS_lstat, filename, buf);
}
