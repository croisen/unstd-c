#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_set_tid_address(int *tidptr) {
    return __syscall(__sys_linux_set_tid_address, tidptr);
}
