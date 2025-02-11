#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int stat(const char *restrict file, struct stat *restrict buf) {
  return _syscall(SYS_stat, file, buf);
}
