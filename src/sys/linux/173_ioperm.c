#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ioperm(usize from, usize num, int turn_on) {
    return __syscall(__sys_linux_ioperm, from, num, turn_on);
}
