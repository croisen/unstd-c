#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fanotify_init(unsigned int flags, unsigned int event_f_flags) {
    return __syscall(__sys_linux_fanotify_init, flags, event_f_flags);
}
