#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_io_getevents(aio_context_t ctx_id, long min_nr, long nr, struct io_event *events) {
    return __syscall(__sys_linux_io_getevents, ctx_id, min_nr, nr, events);
}
