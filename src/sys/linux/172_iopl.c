#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_iopl(unsigned int level, struct pt_regs *regs) {
    return __syscall(__sys_linux_iopl, level, regs);
}
