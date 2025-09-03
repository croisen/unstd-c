#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_modify_ldt(int func, void *ptr, usize bytecount) {
    return __syscall(__sys_linux_modify_ldt, func, ptr, bytecount);
}
