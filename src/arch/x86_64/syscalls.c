#include "integer.h"
#include "sys/linux/syscall.h"

usize _syscall0(usize no)
{
    usize ret;
    __asm__ volatile("syscall" : "=a"(ret) : "a"(no) : "rcx", "r11", "memory");
    return ret;
}

usize _syscall1(usize no, usize a)
{
    usize ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(no), "D"(a)
                     : "rcx", "r11", "memory");
    return ret;
}

usize _syscall2(usize no, usize a, usize b)
{
    usize ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b)
                     : "rcx", "r11", "memory");
    return ret;
}

usize _syscall3(usize no, usize a, usize b, usize c)
{
    usize ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c)
                     : "rcx", "r11", "memory");
    return ret;
}

usize _syscall4(usize no, usize a, usize b, usize c, usize d)
{
    usize ret;
    __asm__ volatile("mov %5, %%r10\n"
                     "syscall\n"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c), "r"(d)
                     : "r10", "rcx", "r11", "memory");
    return ret;
}

usize _syscall5(usize no, usize a, usize b, usize c, usize d, usize e)
{
    usize ret;
    __asm__ volatile("mov %5, %%r10\n"
                     "mov %6, %%r8\n"
                     "syscall\n"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c), "r"(d), "r"(e)
                     : "r10", "r8", "rcx", "r11", "memory");
    return ret;
}

usize _syscall6(usize no, usize a, usize b, usize c, usize d, usize e, usize f)
{
    usize ret;
    __asm__ volatile("mov %5, %%r10\n"
                     "mov %6, %%r8\n"
                     "mov %7, %%r9\n"
                     "syscall\n"
                     : "=a"(ret)
                     : "a"(no), "D"(a), "S"(b), "d"(c), "r"(d), "r"(e), "r"(f)
                     : "r10", "r8", "r9", "rcx", "r11", "memory");
    return ret;
}
