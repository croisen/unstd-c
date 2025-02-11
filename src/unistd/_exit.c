#include "../misc/internal_syscall.h"
#include "unistd.h"

void _exit(int status) {
  _syscall(60, status);
  __builtin_unreachable();
}
