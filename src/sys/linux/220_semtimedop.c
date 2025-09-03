#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_semtimedop(int semid, struct sembuf *tsops, unsigned nsops, const struct timespec *timeout) {
    return __syscall(__sys_linux_semtimedop, semid, tsops, nsops, timeout);
}
