#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_tee(int fdin, int fdout, usize len, unsigned int flags) {
    return __syscall(__sys_linux_tee, fdin, fdout, len, flags);
}
