#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_syslog(int type, char *buf, int len) {
    return __syscall(__sys_linux_syslog, type, buf, len);
}
