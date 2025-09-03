#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_semctl(int semid, int semnum, int cmd, union semun arg)
{
    usize a = (usize)arg.buf;
    return __syscall(__sys_linux_semctl, semid, semnum, cmd, a);
}
