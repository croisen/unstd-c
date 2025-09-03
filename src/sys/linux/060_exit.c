#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_exit(int error_code) {
    return __syscall(__sys_linux_exit, error_code);
}
