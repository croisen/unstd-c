#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_io_destroy(aio_context_t ctx) {
    return __syscall(__sys_linux_io_destroy, ctx);
}
