#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_msgrcv(int msqid, struct msgbuf *msgp, usize msgsz, long msgtyp, int msgflg) {
    return __syscall(__sys_linux_msgrcv, msqid, msgp, msgsz, msgtyp, msgflg);
}
