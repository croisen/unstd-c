#include "stdlib.h"

void _start(void) {
  long status;
  __asm__ volatile("mov 24(%%rsp), %%rdi\n"
                   "lea 32(%%rsp), %%rsi\n"
                   "call main\n"
                   : "=a"(status)
                   :
                   : "rcx", "r11", "memory");

  exit(status);
}
