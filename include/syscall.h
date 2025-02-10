#ifndef SYSCALL_H
#define SYSCALL_H

typedef long _sca;

#define SC_CAT_(a, b) a##b
#define SC_CAT(a, b) SC_CAT_(a, b)
#define SC_NARGS_(a, b, c, d, e, f, n, ...) n
#define SC_NARGS(...) SC_NARGS_(__VA_ARGS__, 5, 4, 3, 2, 1, 0)

#define __syscall0(no) _syscall0((_sca)no)
#define __syscall1(no, a) _syscall1((_sca)no, (_sca)a)
#define __syscall2(no, a, b) _syscall2((_sca)no, (_sca)a, (_sca)b)
#define __syscall3(no, a, b, c) _syscall3((_sca)no, (_sca)a, (_sca)b, (_sca)c)
#define __syscall4(no, a, b, c, d)                                             \
  _syscall4((_sca)no, (_sca)a, (_sca)b, (_sca)c, (_sca)d)
#define __syscall5(no, a, b, c, d, e)                                          \
  _syscall5((_sca)no, (_sca)a, (_sca)b, (_sca)c, (_sca)d, (_sca)e)
#define __syscall6(no, a, b, c, d, e, f)                                       \
  _syscall6((_sca)no, (_sca)a, (_sca)b, (_sca)c, (_sca)d, (_sca)e, (_sca)f)

#define syscall(...) SC_CAT(__syscall, SC_NARGS(__VA_ARGS__))(__VA_ARGS__)

_sca _syscall0(_sca no);
_sca _syscall1(_sca no, _sca a);
_sca _syscall2(_sca no, _sca a, _sca b);
_sca _syscall3(_sca no, _sca a, _sca b, _sca c);
_sca _syscall4(_sca no, _sca a, _sca b, _sca c, _sca d);
_sca _syscall5(_sca no, _sca a, _sca b, _sca c, _sca d, _sca e);
_sca _syscall6(_sca no, _sca a, _sca b, _sca c, _sca d, _sca e, _sca f);

#endif /* SYSCALL_H */
