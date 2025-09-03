#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mq_getsetattr(mqd_t mqdes, const struct mq_attr *u_mqstat, struct mq_attr *u_omqstat) {
    return __syscall(__sys_linux_mq_getsetattr, mqdes, u_mqstat, u_omqstat);
}
