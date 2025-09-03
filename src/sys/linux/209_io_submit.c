#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp) {
    return __syscall(__sys_linux_io_submit, ctx_id, nr, iocbpp);
}
