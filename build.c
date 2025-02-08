#define NOBITA_IMPL
#include "nobita.h"

void build(Nobita_Build *b) {
  Nobita_Try_Rebuild(b, __FILE__);

  Nobita_CMD *crt = Nobita_Build_Add_CMD(b, "crt");
  Nobita_CMD_Add_Args(crt, "cp", NULL);
  Nobita_Target_Add_Fmt_Arg(crt, NOBITA_T_CUSTOM_CMD,
                            "%s/nobita-cache/crt/custom/crt/crt0.o",
                            Nobita_GetCed(b));
  Nobita_Target_Add_Fmt_Arg(crt, NOBITA_T_CUSTOM_CMD, "%s", Nobita_GetLib(b));
  Nobita_Target_Set_Build_Tool(crt, NOBITA_BT_GCC);
  Nobita_Target_Add_Cflags(crt, "-nostdinc", "-nostdlib", NULL);
  Nobita_Target_Add_Sources(crt, "crt/crt0.c", NULL);

  Nobita_Exe *hello = Nobita_Build_Add_Exe(b, "hello");
  Nobita_Target_Add_Fmt_Arg(hello, NOBITA_T_LDFLAGS, "%s/crt0.o",
                            Nobita_GetLib(b));
  Nobita_Target_Set_Build_Tool(hello, NOBITA_BT_GCC);
  Nobita_Target_Add_Cflags(hello, "-nostdinc", "-nostdlib", NULL);
  Nobita_Target_Add_Sources(hello, "test/hello.c", NULL);
  Nobita_Target_Add_Deps(hello, crt, NULL);
}
