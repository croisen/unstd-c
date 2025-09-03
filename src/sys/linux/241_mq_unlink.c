#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mq_unlink(const char *u_name) {
    return __syscall(__sys_linux_mq_unlink, u_name);
}
