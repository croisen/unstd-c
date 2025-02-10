#include "syscall.h"
#include "unistd.h"

void _exit(int status) {
  syscall(60, status);
  __builtin_unreachable();
}
