#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_io_setup(unsigned nr_events, aio_context_t *ctxp) {
    return __syscall(__sys_linux_io_setup, nr_events, ctxp);
}
