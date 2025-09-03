#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mq_timedreceive(mqd_t mqdes, char *u_msg_ptr, usize msg_len, unsigned int *u_msg_prio, const struct timespec *u_abs_timeout) {
    return __syscall(__sys_linux_mq_timedreceive, mqdes, u_msg_ptr, msg_len, u_msg_prio, u_abs_timeout);
}
