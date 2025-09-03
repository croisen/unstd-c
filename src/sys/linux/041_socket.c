#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_socket(int family, int type, int protocol) {
    return __syscall(__sys_linux_socket, family, type, protocol);
}
