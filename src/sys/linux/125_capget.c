#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_capget(cap_user_header_t header, cap_user_data_t dataptr) {
    return __syscall(__sys_linux_capget, header, dataptr);
}
