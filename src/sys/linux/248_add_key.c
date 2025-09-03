#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_add_key(const char *_type, const char *_description, const void *_payload, usize plen ) {
    return __syscall(__sys_linux_add_key, _type, _description, _payload, plen);
}
