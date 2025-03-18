#include "stdlib.h"

void _start(void) {
  __asm__ volatile("mov  8(%%rsp), %%rdi\n"
                   "lea 16(%%rsp), %%rsi\n"
                   "call main\n"
                   "mov %%rax, %%rdi\n"
                   "call exit\n"
                   :
                   :
                   : "rdi", "rsi", "memory");
}
