#include "../misc/internal_syscall.h"
#include "stdarg.h"
#include "unistd.h"

long syscall(long no, ...)
{
    va_list va;
    _sca a, b, c, d, e, f;
    va_start(va, no);
    a = va_arg(va, _sca);
    b = va_arg(va, _sca);
    c = va_arg(va, _sca);
    d = va_arg(va, _sca);
    e = va_arg(va, _sca);
    f = va_arg(va, _sca);
    va_end(va);

    return _syscall(no, a, b, c, d, e, f);
}
