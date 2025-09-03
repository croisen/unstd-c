#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_capset(cap_user_header_t header, const cap_user_data_t data) {
    return __syscall(__sys_linux_capset, header, data);
}
