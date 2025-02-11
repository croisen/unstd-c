#include "../misc/internal_syscall.h"

_sca _syscall0(_sca no)
{
    _sca ret;
    __asm__ volatile("syscall" : "=a"(ret) : "a"(no) : "rcx", "r11", "memory");
    return ret;
}

_sca _syscall1(_sca no, _sca a)
{
    _sca ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(no), "D"(a)
                     : "rcx", "r11", "memory");
    return ret;
}

_sca _syscall2(_sca no, _sca a, _sca b)
{
    _sca ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b)
                     : "rcx", "r11", "memory");
    return ret;
}

_sca _syscall3(_sca no, _sca a, _sca b, _sca c)
{
    _sca ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c)
                     : "rcx", "r11", "memory");
    return ret;
}

_sca _syscall4(_sca no, _sca a, _sca b, _sca c, _sca d)
{
    _sca ret;
    __asm__ volatile("mov %5, %%r10\n"
                     "syscall\n"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c), "r"(d)
                     : "rcx", "r11", "memory");
    return ret;
}

_sca _syscall5(_sca no, _sca a, _sca b, _sca c, _sca d, _sca e)
{
    _sca ret;
    __asm__ volatile("mov %5, %%r10\n"
                     "mov %6, %%r8\n"
                     "syscall\n"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c), "r"(d), "r"(e)
                     : "rcx", "r11", "memory");
    return ret;
}

_sca _syscall6(_sca no, _sca a, _sca b, _sca c, _sca d, _sca e, _sca f)
{
    _sca ret;
    __asm__ volatile("mov %5, %%r10\n"
                     "mov %6, %%r8\n"
                     "mov %7, %%r9\n"
                     "syscall\n"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c), "r"(d), "r"(e), "r"(f)
                     : "rcx", "r11", "memory");
    return ret;
}
