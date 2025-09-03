#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_shmctl(int shmid, int cmd, struct shmid_ds *buf) {
    return __syscall(__sys_linux_shmctl, shmid, cmd, buf);
}
