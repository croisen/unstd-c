# unstd-c

## Moved to Codeberg

[here](https://codeberg.org/croisen/unstd-c)

------------

A recreation of the C stdlib built on top of Linux syscalls and inline assembly
for x86\_64 arch

## References

- [Linux x86\_64 syscalls table](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
- [System V ABI - x86\_64](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
- [ASM cheatsheet - x86\_64](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
- [GCC's extended inline assembly docs](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html)
- [Linux errno list](https://gist.github.com/greggyNapalm/2413028)
- [C99 Standard](https://www.dii.uchile.cl/~daespino/files/Iso_C_1999_definition.pdf)
- [GCC Statement Macros](http://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html)

## TODOs

- [ ] The \_start
  - [x] Have a custom exit status
  - [x] Make the C runtime object
  - [x] Pass the usual args to main via inline assembly
  - [x] Make a generic syscall function
  - [x] Implement the syscalls as C functions
  - [x] Rely more on the built-in headers for linux related functions
  - [ ] A config header that gives information about the host machine from
            the compiler predefs
  - [ ] Check on the syscalls that have a suffix of 64 and make them generic?
  - [ ] Implement C inline assembly syscalls for other architectures as well
- [ ] Implement the standard function
  - [ ] Allocation
  - [ ] Strings
  - [ ] File Paths
  - [ ] IO
