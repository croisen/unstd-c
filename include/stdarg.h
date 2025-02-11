#ifndef STDARG_H
#define STDARG_H

typedef __builtin_va_list va_list;

#define va_start(v, a) __builtin_va_start(v, a)
#define va_arg(v, t) __builtin_va_arg(v, t)
#define va_end(v) __builtin_va_end(v)
#define va_copy(d, s) __builtin_va_copy(d, s)

#endif /* STDARG_H */
