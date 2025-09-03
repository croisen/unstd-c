#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_shmat(int shmid, char *shmaddr, int shmflg) {
    return __syscall(__sys_linux_shmat, shmid, shmaddr, shmflg);
}
