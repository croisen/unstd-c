#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_socketpair(int family, int type, int protocol, int *usockvec) {
    return __syscall(__sys_linux_socketpair, family, type, protocol, usockvec);
}
