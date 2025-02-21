#include "stdlib.h"

void _start(void) {
  __asm__ volatile("mov (%%rsp), %%rdi\n"
                   "lea 8(%%rsp), %%rsi\n"
                   "call main\n"
                   "mov %%rax, %%rdi\n"
                   "call exit\n"
                   :
                   :
                   : "rcx", "r11", "memory");
}
