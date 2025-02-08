#define NOBITA_IMPL
#include "nobita.h"

void build(Nobita_Build *b) {
  Nobita_Exe *hello = Nobita_Build_Add_Exe(b, "hello");
  Nobita_Target_Set_Build_Tool(hello, NOBITA_BT_GCC);
  Nobita_Target_Add_Cflags(hello, "-nostdinc", "-nostdlib", NULL);
  Nobita_Target_Add_Sources(hello, "test/hello.c", NULL);
}
