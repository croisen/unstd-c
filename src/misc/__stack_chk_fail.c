#include "stdlib.h"
#include "unistd.h"

void __stack_chk_fail(void)
{
    write(1, "Stack check failed\n", 19);
    exit(1);
}
