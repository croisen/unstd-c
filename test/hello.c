void _start(void) {
  __asm__ volatile("mov $60, %%rax\n"
                   "mov $69, %%rdi\n"
                   "syscall\n"
                   :
                   :
                   : "rcx", "r11", "memory");
}
