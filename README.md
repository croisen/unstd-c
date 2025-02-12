# unstd-c

A recreation of the C stdlib built on top of Linux syscalls and inline assembly
for x86_64 arch

## References

-   [Linux x86_64 syscalls table](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
-   [System V ABI - x86_64](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
-   [ASM cheatsheet - x86_64](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
-   [GCC's extended inline assembly docs](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html)
-   [Linux errno list](https://gist.github.com/greggyNapalm/2413028)
-   [C99 Standard](https://www.dii.uchile.cl/~daespino/files/Iso_C_1999_definition.pdf)
-   [GCC Statement Macros](http://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html)

## TODOs

-   [x] Have a custom exit status
-   [x] Make the C runtime object
-   [x] Pass the usual args to main via inline assembly
-   [x] Make a generic syscall function
-   [x] Implement the syscalls as C functions
-   [x] Rely more on the built-in headers for linux related functions
-   [ ] Implement the other C std functions

## The I dunno issues

-   The signal stuff
-   sbrk and brk
