#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_msgctl(int msqid, int cmd, struct msqid_ds *buf) {
    return __syscall(__sys_linux_msgctl, msqid, cmd, buf);
}
