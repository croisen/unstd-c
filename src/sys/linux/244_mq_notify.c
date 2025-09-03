#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mq_notify(mqd_t mqdes, const struct sigevent *u_notification) {
    return __syscall(__sys_linux_mq_notify, mqdes, u_notification);
}
