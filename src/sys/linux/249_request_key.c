#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_request_key(const char *_type, const char *_description, const char *_callout_info, key_serial_t destringid) {
    return __syscall(__sys_linux_request_key, _type, _description, _callout_info, destringid);
}
