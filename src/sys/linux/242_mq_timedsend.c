#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mq_timedsend(mqd_t mqdes, const char *u_msg_ptr, usize msg_len, unsigned int msg_prio, const struct timespec *u_abs_timeout) {
    return __syscall(__sys_linux_mq_timedsend, mqdes, u_msg_ptr, msg_len, msg_prio, u_abs_timeout);
}
