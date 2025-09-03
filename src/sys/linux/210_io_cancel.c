#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_io_cancel(aio_context_t ctx_id, struct iocb *iocb, struct io_event *result) {
    return __syscall(__sys_linux_io_cancel, ctx_id, iocb, result);
}
