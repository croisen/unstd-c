void _start(void) {
  __asm__ volatile("mov 8(%%rsp), %%rdi\n"
                   "lea 16(%%rsp), %%rsi\n"
                   "call main\n"
                   "mov %%rax, %%rdi\n"
                   "mov $60, %%rax\n"
                   "syscall\n"
                   :
                   :
                   : "rcx", "r11", "memory");
}
