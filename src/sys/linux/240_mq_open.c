#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mq_open(const char *u_name, int oflag, mode_t mode, struct mq_attr *u_attr) {
    return __syscall(__sys_linux_mq_open, u_name, oflag, mode, u_attr);
}
