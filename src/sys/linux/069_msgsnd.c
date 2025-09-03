#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_msgsnd(int msqid, struct msgbuf *msgp, usize msgsz, int msgflg) {
    return __syscall(__sys_linux_msgsnd, msqid, msgp, msgsz, msgflg);
}
