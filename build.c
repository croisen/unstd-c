#define NOBITA_IMPL
#include "nobita.h"

void build(Nobita_Build *b)
{
    Nobita_Try_Rebuild(b, __FILE__);

    Nobita_Shared_Lib *lc = Nobita_Build_Add_Shared_Lib(b, "c");
    Nobita_Target_Set_Build_Tool(lc, NOBITA_BT_GCC);
    Nobita_Target_Add_Cflags(lc, 
            "-Wall", "-Wextra", "-Wpedantic",
            "-nostdlib", "-g", "-fPIC",
    NULL);
    Nobita_Target_Add_Sources(lc, "src/*/*.c", "src/*/*/*.c", NULL);
    Nobita_Target_Add_Headers(lc, "include",
        "errno.h", "stdarg.h", "stddef.h", "stdlib.h", "stdio.h",
        "syscall.h", "unistd.h", "sys/stat.h", "sys/types.h", NULL
    );

    Nobita_CMD *crt = Nobita_Build_Add_CMD(b, "crt");
    Nobita_CMD_Add_Args(crt, "cp", NULL);
    Nobita_Target_Add_Fmt_Arg(
        crt, NOBITA_T_CUSTOM_CMD, "%s/nobita-cache/crt/custom/crt/crt0.o",
        Nobita_GetCed(b)
    );
    Nobita_Target_Add_Fmt_Arg(crt, NOBITA_T_CUSTOM_CMD, "%s", Nobita_GetLib(b));
    Nobita_Target_Set_Build_Tool(crt, NOBITA_BT_GCC);
    Nobita_Target_Add_Cflags(crt, "-nostdlib", "-g", NULL);
    Nobita_Target_Add_Sources(crt, "crt/crt0.c", NULL);
    Nobita_Target_Add_Deps(crt, lc, NULL);

    Nobita_Exe *hello = Nobita_Build_Add_Exe(b, "hello");
    Nobita_Target_Add_Fmt_Arg(
        hello, NOBITA_T_LDFLAGS, "%s/crt0.o", Nobita_GetLib(b)
    );
    Nobita_Target_Set_Build_Tool(hello, NOBITA_BT_GCC);
    Nobita_Target_Add_Cflags(hello, "-nostdlib", "-g", NULL);
    Nobita_Target_Add_Sources(hello, "test/hello.c", NULL);
    Nobita_Target_Add_LDflags(hello, "-lc", NULL);
    Nobita_Target_Add_Fmt_Arg(
        hello, NOBITA_T_LDFLAGS, "-Wl,-rpath,%s", Nobita_GetLib(b)
    );

    Nobita_Target_Add_Deps(hello, crt, NULL);
}
