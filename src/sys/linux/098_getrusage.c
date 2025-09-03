#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getrusage(int who, struct rusage *ru) {
    return __syscall(__sys_linux_getrusage, who, ru);
}
