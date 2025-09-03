#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rseq(void) {
    return __syscall(__sys_linux_rseq);
}
