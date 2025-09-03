#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_adjtimex(struct timex *txc_p) {
    return __syscall(__sys_linux_adjtimex, txc_p);
}
