/**
 * Copyright © 2024 croisen
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef NOBITA_H
#define NOBITA_H

typedef struct nobita_build Nobita_Build;
typedef struct nobita_target Nobita_Exe;
typedef struct nobita_target Nobita_Shared_Lib;
typedef struct nobita_target Nobita_Static_Lib;
typedef struct nobita_target Nobita_CMD;

enum nobita_argtype {
  NOBITA_T_CFLAGS,
  NOBITA_T_LDFLAGS,
  NOBITA_T_CUSTOM_CMD,
};

enum nobita_build_tool {
  NOBITA_BT_GCC,
  NOBITA_BT_GPP,
  NOBITA_BT_LLVM,
  NOBITA_BT_LLVMPP,
  NOBITA_BT_MSVC,
};

extern void build(Nobita_Build *b);

void Nobita_Try_Rebuild(Nobita_Build *b, const char *build_file);

void Nobita_Free_Later(Nobita_Build *b, void *ptr);

Nobita_Exe *Nobita_Build_Add_Exe(Nobita_Build *b, const char *name);
Nobita_Shared_Lib *Nobita_Build_Add_Shared_Lib(Nobita_Build *b,
                                               const char *name);
Nobita_Static_Lib *Nobita_Build_Add_Static_Lib(Nobita_Build *b,
                                               const char *name);
Nobita_CMD *Nobita_Build_Add_CMD(Nobita_Build *b, const char *name);
// Untested
Nobita_CMD *Nobita_Build_Add_Nobita(Nobita_Build *b,
                                    const char *nobita_build_src);

void Nobita_Target_Set_Build_Tool(struct nobita_target *t,
                                  enum nobita_build_tool bt);
void Nobita_CMD_Add_Args(Nobita_CMD *c, ...);

#ifdef __GNUC__
void Nobita_Target_Add_Fmt_Arg(struct nobita_target *t, enum nobita_argtype a,
                               const char *fmt, ...)
    __attribute__((format(printf, 3, 4)));
#else
void Nobita_Target_Add_Fmt_Arg(struct nobita_target *t, enum nobita_argtype a,
                               const char *fmt, ...);
#endif /* __GNUC__ */

void Nobita_Target_Add_Cflags(struct nobita_target *t, ...);
void Nobita_Target_Add_Sources(struct nobita_target *t, ...);
void Nobita_Target_Add_LDflags(struct nobita_target *t, ...);
void Nobita_Target_Add_Deps(struct nobita_target *t, ...);
void Nobita_Target_Add_Headers(struct nobita_target *t, const char *parent,
                               ...);

char *Nobita_GetCwd(Nobita_Build *b);
char *Nobita_GetCed(Nobita_Build *b);
char *Nobita_GetPrefix(Nobita_Build *b);
char *Nobita_GetInclude(Nobita_Build *b);
char *Nobita_GetBin(Nobita_Build *b);
char *Nobita_GetLib(Nobita_Build *b);

#endif /* NOBITA_H */

#define NOBITA_IMPL
#ifdef NOBITA_IMPL

#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32

#include <errno.h>
#include <glob.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef pid_t nobita_pid;
#define NOBITA_PATHSEP "/"
#define NOBITA_EXECUT_EXT ".elf"
#define NOBITA_SHARED_EXT ".so"
#define NOBITA_STATIC_EXT ".a"

#else

#include <stdint.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef HANDLE nobita_pid;
#define NOBITA_PATHSEP "\\"
#define NOBITA_EXECUT_EXT ".exe"
#define NOBITA_SHARED_EXT ".dll"
#define NOBITA_STATIC_EXT ".lib"

#endif /* _WIN32 */

enum nobita_target_type {
  NOBITA_EXECUTABLE,
  NOBITA_SHARED_LIB,
  NOBITA_STATIC_LIB,
  NOBITA_CUSTOM_CMD,
};

struct nobita_header {
  char *parent;
  char *header;
};

struct nobita_target {
  char *name;
  bool built;
  bool rebuilt;
  enum nobita_target_type target_type;

  struct {
    enum nobita_build_tool bt;

    char *cc;
    char *to_obj;
    char *to_exe;
    char *to_lib;
    char *rename_obj;

    char *inc_dir;
    char *lib_dir;

    char *ar;
    char *ar_opts;
  } comp_opts;

  size_t cflags_used;
  size_t cflags_size;
  char **cflags;

  size_t sources_used;
  size_t sources_size;
  char **sources;

  size_t objects_used;
  size_t objects_size;
  char **objects;

  size_t ldflags_used;
  size_t ldflags_size;
  char **ldflags;

  size_t full_cmd_used;
  size_t full_cmd_size;
  char **full_cmd;

  size_t custom_cmd_used;
  size_t custom_cmd_size;
  char **custom_cmd;

  size_t headers_used;
  size_t headers_size;
  struct nobita_header *headers;

  size_t deps_used;
  size_t deps_size;
  void **deps;

  struct nobita_build *b;
};

struct nobita_build {
  size_t deps_used;
  size_t deps_size;
  void **deps;

  size_t free_later_used;
  size_t free_later_size;
  void **free_later;

  size_t proc_queue_used;
  size_t proc_queue_size;
  nobita_pid *proc_queue;

  size_t proc_names_used;
  size_t proc_names_size;
  char **proc_names;

  int argc;
  char **argv;
  bool was_self_rebuilt;

  char *ced;
  char *cwd;
  char *prefix;
  char *include;
  char *bin;
  char *lib;
};

static struct nobita_target *nobita_build_add_target(struct nobita_build *b,
                                                     const char *name);

static nobita_pid nobita_proc_exec(char **cmd, char *joined_cmd);
static int nobita_proc_wait(nobita_pid pid, bool pause);

static void nobita_proc_append(struct nobita_build *b, char **cmd);
static void nobita_proc_wait_one(struct nobita_build *b);
static void nobita_proc_wait_all(struct nobita_build *b);

static void nobita_mkdir_recursive(const char *path);
static bool nobita_is_a_newer(const char *a, const char *b);
static bool nobita_file_exist(const char *path);
static bool nobita_dir_exist(const char *path);

static void nobita_build_target(struct nobita_target *t);
static void nobita_cp(const char *dest, const char *src);
static char *nobita_strjoinl(const char *join, ...);
static char *nobita_strjoinv(const char *join, char **v);
static char *nobita_getcwd(void);
static char *nobita_getced(const char *arv0);
static char *nobita_strdup(const char *);
static void nobita_dirname(char *p);

static bool nobita_build_failed = false;
static size_t nobita_max_proc_count = 4;

#define vector_init(ptr, name)                                                 \
  do {                                                                         \
    if (nobita_build_failed)                                                   \
      break;                                                                   \
                                                                               \
    (ptr)->name##_size = 8;                                                    \
    (ptr)->name##_used = 0;                                                    \
    (ptr)->name = calloc(8, sizeof(*(ptr)->name));                             \
    if ((ptr)->name == NULL) {                                                 \
      fprintf(stderr, "Failed to initialize vector named %s\n", #name);        \
      nobita_build_failed = true;                                              \
    }                                                                          \
  } while (false)

#define vector_free(ptr, name)                                                 \
  do {                                                                         \
    free((ptr)->name);                                                         \
    (ptr)->name##_size = 0;                                                    \
    (ptr)->name##_used = 0;                                                    \
    (ptr)->name = NULL;                                                        \
  } while (false)

#define vector_append(ptr, name, item)                                         \
  do {                                                                         \
    if (nobita_build_failed)                                                   \
      break;                                                                   \
                                                                               \
    if ((ptr)->name##_size <= (ptr)->name##_used + 1) {                        \
      void *data = calloc((ptr)->name##_size * 2, sizeof(*(ptr)->name));       \
      if (data == NULL) {                                                      \
        nobita_build_failed = true;                                            \
        fprintf(stderr,                                                        \
                "Failed to append data to vector named %s in struct %s\n",     \
                #name, #ptr);                                                  \
                                                                               \
        break;                                                                 \
      }                                                                        \
                                                                               \
      memcpy(data, (ptr)->name, (ptr)->name##_used * sizeof(*(ptr)->name));    \
                                                                               \
      free((ptr)->name);                                                       \
      (ptr)->name = data;                                                      \
      (ptr)->name##_size *= 2;                                                 \
    }                                                                          \
                                                                               \
    (ptr)->name[(ptr)->name##_used] = item;                                    \
    (ptr)->name##_used += 1;                                                   \
  } while (false)

#define vector_append_vector(dest, dest_name, src, src_name)                   \
  do {                                                                         \
    if (nobita_build_failed)                                                   \
      break;                                                                   \
                                                                               \
    for (size_t nobita_iter_##src_name = 0;                                    \
         nobita_iter_##src_name < (src)->src_name##_used;                      \
         nobita_iter_##src_name++)                                             \
      vector_append(dest, dest_name, (src)->src_name[nobita_iter_##src_name]); \
  } while (false)

void Nobita_Free_Later(Nobita_Build *b, void *ptr) {
  vector_append(b, free_later, ptr);
}

Nobita_Exe *Nobita_Build_Add_Exe(Nobita_Build *b, const char *name) {
  if (nobita_build_failed)
    return NULL;

  Nobita_Exe *e = nobita_build_add_target(b, name);
  if (e == NULL)
    return e;

  e->target_type = NOBITA_EXECUTABLE;
  return e;
}

Nobita_Shared_Lib *Nobita_Build_Add_Shared_Lib(Nobita_Build *b,
                                               const char *name) {
  if (nobita_build_failed)
    return NULL;

  Nobita_Shared_Lib *l = nobita_build_add_target(b, name);
  if (l == NULL)
    return l;

  l->target_type = NOBITA_SHARED_LIB;
  return l;
}

Nobita_Static_Lib *Nobita_Build_Add_Static_Lib(Nobita_Build *b,
                                               const char *name) {
  if (nobita_build_failed)
    return NULL;

  Nobita_Shared_Lib *l = nobita_build_add_target(b, name);
  if (l == NULL)
    return l;

  l->target_type = NOBITA_STATIC_LIB;
  return l;
}

Nobita_CMD *Nobita_Build_Add_CMD(Nobita_Build *b, const char *name) {
  if (nobita_build_failed)
    return NULL;

  Nobita_CMD *c = nobita_build_add_target(b, name);
  if (c == NULL)
    return c;

  c->target_type = NOBITA_CUSTOM_CMD;
  return c;
}

Nobita_CMD *Nobita_Build_Add_Nobita(Nobita_Build *b,
                                    const char *nobita_build_src) {
  char *exe = nobita_strdup(nobita_build_src);
  *strrchr(exe, '.') = 0;

  Nobita_CMD *run = Nobita_Build_Add_CMD(b, exe);

  if (nobita_is_a_newer(nobita_build_src, exe)) {
    Nobita_CMD *cmd = Nobita_Build_Add_CMD(b, nobita_build_src);
#if defined(__clang__)
    Nobita_CMD_Add_Args(cmd, "clang", "-Wall", "-Wpedantic", "-Wextra", "-O3",
                        "-g", "-fsanitize=address", "-o", exe, nobita_build_src,
                        NULL);
#elif defined(__GNUC__)
    Nobita_CMD_Add_Args(cmd, "gcc", "-Wall", "-Wpedantic", "-Wextra", "-O3",
                        "-g", "-fsanitize=address", "-o", exe, nobita_build_src,
                        NULL);
#else
    Nobita_CMD_Add_Args(cmd, "cl", "/Wall", "/O2", "/Zi", "/fsanitize=address",
                        "-Fe:", exe, nobita_build_src, NULL);
#endif
    Nobita_Target_Add_Deps(run, cmd, NULL);
  }

  Nobita_CMD_Add_Args(run, exe, NULL);
  Nobita_Target_Add_Fmt_Arg(run, NOBITA_T_CUSTOM_CMD, "%lu",
                            nobita_max_proc_count);
  Nobita_CMD_Add_Args(run, b->prefix, NULL);
  free(exe);
  return run;
}

void Nobita_Target_Set_Build_Tool(struct nobita_target *t,
                                  enum nobita_build_tool bt) {
  if (nobita_build_failed)
    return;

  t->comp_opts.bt = bt;
  if (bt != NOBITA_BT_MSVC) {
    Nobita_Target_Add_Fmt_Arg(t, NOBITA_T_LDFLAGS, "%s%s", "-L", t->b->lib);
    Nobita_Target_Add_Fmt_Arg(t, NOBITA_T_CFLAGS, "%s%s", "-I", t->b->include);
  } else {
    vector_append(t, ldflags, "/link");
    Nobita_Target_Add_Fmt_Arg(t, NOBITA_T_CFLAGS, "%s%s", "/I", t->b->include);
    Nobita_Target_Add_Fmt_Arg(t, NOBITA_T_LDFLAGS, "%s%s",
                              "/LIBPATH:", t->b->lib);
  }

  switch (bt) {
  case NOBITA_BT_GCC:
    t->comp_opts.cc = "gcc";
    t->comp_opts.to_exe = "-o";
    t->comp_opts.to_obj = "-c";
    t->comp_opts.rename_obj = NULL;
    t->comp_opts.to_lib = "-shared";

    t->comp_opts.inc_dir = "-I";
    t->comp_opts.lib_dir = "-L";

    t->comp_opts.ar = "ar";
    t->comp_opts.ar_opts = "rcs";
    break;
  case NOBITA_BT_GPP:
    t->comp_opts.cc = "g++";
    t->comp_opts.to_exe = "-o";
    t->comp_opts.to_obj = "-c";
    t->comp_opts.rename_obj = NULL;
    t->comp_opts.to_lib = "-shared";

    t->comp_opts.inc_dir = "-I";
    t->comp_opts.lib_dir = "-L";

    t->comp_opts.ar = "ar";
    t->comp_opts.ar_opts = "rcs";
    break;
  case NOBITA_BT_LLVM:
    t->comp_opts.cc = "clang";
    t->comp_opts.to_exe = "-o";
    t->comp_opts.to_obj = "-c";
    t->comp_opts.rename_obj = NULL;
    t->comp_opts.to_lib = "-shared";

    t->comp_opts.inc_dir = "-I";
    t->comp_opts.lib_dir = "-L";

    t->comp_opts.ar = "llvm-ar";
    t->comp_opts.ar_opts = "rcs";
    break;
  case NOBITA_BT_LLVMPP:
    t->comp_opts.cc = "clang++";
    t->comp_opts.to_exe = "-o";
    t->comp_opts.to_obj = "-c";
    t->comp_opts.rename_obj = NULL;
    t->comp_opts.to_lib = "-shared";

    t->comp_opts.inc_dir = "-I";
    t->comp_opts.lib_dir = "-L";

    t->comp_opts.ar = "llvm-ar";
    t->comp_opts.ar_opts = "rcs";
    break;
  case NOBITA_BT_MSVC:
    t->comp_opts.cc = "cl.exe";
    t->comp_opts.to_exe = "/Fe:";
    t->comp_opts.to_obj = "/c";
    t->comp_opts.rename_obj = "/Fo:";
    t->comp_opts.to_lib = "/LD";

    t->comp_opts.inc_dir = "/I";
    t->comp_opts.lib_dir = "/LIBPATH:";

    t->comp_opts.ar = "lib.exe";
    t->comp_opts.ar_opts = "/OUT:";
    break;
  }
}

void Nobita_Target_Add_Cflags(struct nobita_target *t, ...) {
  if (nobita_build_failed)
    return;

  va_list va;
  va_start(va, t);

  char *arg = va_arg(va, char *);
  while (arg != NULL) {
    vector_append(t, cflags, arg);
    arg = va_arg(va, char *);
  }

  va_end(va);
}

void Nobita_Target_Add_Sources(struct nobita_target *t, ...) {
  if (nobita_build_failed)
    return;

  char *append_cache_dir = NULL;
  switch (t->target_type) {
  case NOBITA_EXECUTABLE:
    append_cache_dir = "execut";
    break;
  case NOBITA_SHARED_LIB:
    append_cache_dir = "shared";
    break;
  case NOBITA_STATIC_LIB:
    append_cache_dir = "static";
    break;
  case NOBITA_CUSTOM_CMD:
    append_cache_dir = "custom";
    break;
  }

  va_list va;
  va_start(va, t);

  char *arg = va_arg(va, char *);
  while (arg != NULL) {
#ifndef _WIN32
    glob_t g;
    if (glob(arg, 0, NULL, &g) != 0) {
      nobita_build_failed = true;
      va_end(va);
      fprintf(stderr, "Glob error for pattern %s in add source to target %s\n",
              arg, t->name);

      return;
    }

    for (size_t ii = 0; ii < g.gl_pathc; ii++) {
      char *s =
          nobita_strjoinl(NOBITA_PATHSEP, t->b->ced, g.gl_pathv[ii], NULL);
      char *o =
          nobita_strjoinl(NOBITA_PATHSEP, t->b->ced, "nobita-cache", t->name,
                          append_cache_dir, g.gl_pathv[ii], NULL);
      char *i = strrchr(o, '.');
      i[1] = 'o';
      i[2] = 0;

      vector_append(t, sources, s);
      vector_append(t, objects, o);
      nobita_dirname(o);
      nobita_mkdir_recursive(o);
      *strchr(o, 0) = *NOBITA_PATHSEP;
    }

    globfree(&g);

#else
    WIN32_FIND_DATAA d = {0};
    HANDLE f = FindFirstFileA(arg, &d);
    if (f == INVALID_HANDLE_VALUE) {
      nobita_build_failed = true;
      va_end(va);
      fprintf(stderr, "The glob pattern %s for custom command %s is invalid!\n",
              arg, t->name);

      return;
    }

    char *argdir = nobita_strdup(arg);
    nobita_dirname(argdir);
    char *s =
        nobita_strjoinl(NOBITA_PATHSEP, t->b->ced, argdir, d.cFileName, NULL);
    vector_append(t, sources, s);

    char *i = strrchr(d.cFileName, '.');
    i[1] = 'o';
    i[2] = 'b';
    i[3] = 'j';
    i[4] = 0;
    char *o =
        nobita_strjoinl(NOBITA_PATHSEP, t->b->ced, "nobita-cache", t->name,
                        append_cache_dir, argdir, d.cFileName, NULL);
    vector_append(t, objects, o);
    nobita_dirname(o);
    nobita_mkdir_recursive(o);
    *strchr(o, 0) = *NOBITA_PATHSEP;

    while (FindNextFileA(f, &d)) {
      char *s =
          nobita_strjoinl(NOBITA_PATHSEP, t->b->ced, argdir, d.cFileName, NULL);
      vector_append(t, sources, s);

      char *i = strrchr(d.cFileName, '.');
      i[1] = 'o';
      i[2] = 'b';
      i[3] = 'j';
      i[4] = 0;
      char *o =
          nobita_strjoinl(NOBITA_PATHSEP, t->b->ced, "nobita-cache", t->name,
                          append_cache_dir, argdir, d.cFileName, NULL);

      vector_append(t, objects, o);
      nobita_dirname(o);
      nobita_mkdir_recursive(o);
      *strchr(o, 0) = *NOBITA_PATHSEP;
    }

    free(argdir);
    CloseHandle(f);
#endif /* _WIN32 */

    arg = va_arg(va, char *);
  }

  va_end(va);
}

void Nobita_Target_Add_LDflags(struct nobita_target *t, ...) {
  if (nobita_build_failed)
    return;

  va_list va;
  va_start(va, t);

  char *arg = va_arg(va, char *);
  while (arg != NULL) {
    vector_append(t, ldflags, arg);
    arg = va_arg(va, char *);
  }

  va_end(va);
}

void Nobita_Target_Add_Deps(struct nobita_target *t, ...) {
  if (nobita_build_failed)
    return;

  va_list va;
  va_start(va, t);

  struct nobita_target *arg = va_arg(va, struct nobita_target *);
  while (arg != NULL) {
    vector_append(t, deps, arg);
    arg = va_arg(va, struct nobita_target *);
  }

  va_end(va);
}

void Nobita_CMD_Add_Args(Nobita_CMD *c, ...) {
  if (nobita_build_failed)
    return;

  va_list va;
  va_start(va, c);

  char *arg = va_arg(va, char *);
#ifndef _WIN32
  while (arg != NULL) {
    glob_t g;
    if (glob(arg, GLOB_NOCHECK, NULL, &g) != 0) {
      nobita_build_failed = true;
      va_end(va);
      fprintf(stderr, "The glob pattern %s for custom command %s is invalid!\n",
              arg, c->name);

      return;
    }

    for (size_t i = 0; i < g.gl_pathc; i++)
      vector_append(c, custom_cmd, g.gl_pathv[i]);

    free(g.gl_pathv);
    arg = va_arg(va, char *);
  }
#else
  while (arg != NULL) {
    WIN32_FIND_DATAA d = {0};
    HANDLE f = FindFirstFileA(arg, &d);
    if (f == INVALID_HANDLE_VALUE) {
      vector_append(c, custom_cmd, nobita_strdup(arg));
      arg = va_arg(va, char *);
      continue;
    } else {
      char *argdir = nobita_strdup(arg);
      nobita_dirname(argdir);
      vector_append(c, custom_cmd,
                    nobita_strjoinl(NOBITA_PATHSEP, argdir, d.cFileName, NULL));
      free(argdir);
    }

    char *argdir = nobita_strdup(arg);
    nobita_dirname(argdir);
    while (FindNextFileA(f, &d))
      vector_append(c, custom_cmd,
                    nobita_strjoinl(NOBITA_PATHSEP, argdir, d.cFileName, NULL));

    free(argdir);
    CloseHandle(f);
    arg = va_arg(va, char *);
  }
#endif /* _WIN32 */

  va_end(va);
}

void Nobita_Target_Add_Fmt_Arg(struct nobita_target *t, enum nobita_argtype a,
                               const char *fmt, ...) {
  if (nobita_build_failed)
    return;

  va_list va;
  va_start(va, fmt);
  int64_t arglen = vsnprintf(NULL, 0, fmt, va) + 1;
  va_end(va);

  char *arg = malloc(arglen * sizeof(char));
  if (arg == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "Failed to add formatted arg to target %s\n", t->name);
    return;
  }

  va_start(va, fmt);
  vsprintf(arg, fmt, va);
  va_end(va);

  switch (a) {
  case NOBITA_T_CFLAGS: {
    vector_append(t, cflags, arg);
    Nobita_Free_Later(t->b, arg);
    break;
  }
  case NOBITA_T_LDFLAGS: {
    vector_append(t, ldflags, arg);
    Nobita_Free_Later(t->b, arg);
    break;
  }
  case NOBITA_T_CUSTOM_CMD: {
    vector_append(t, custom_cmd, arg);
    break;
  }
  default:
    break;
  }
}

void Nobita_Try_Rebuild(Nobita_Build *b, const char *build_file) {
#ifdef _WIN32
  printf("Self-rebuilds are not supported on windows...\n");
  return;
#endif

  char *build_exe = b->argv[0];
  char *nobita = __FILE__;
  if (nobita_is_a_newer(build_exe, (char *)build_file) &&
      nobita_is_a_newer(build_exe, nobita))
    return;

  struct nobita_target e = {0};
  vector_init(&e, full_cmd);
#if defined(__clang__)
  vector_append(&e, full_cmd, "clang");
  vector_append(&e, full_cmd, "-Wall");
  vector_append(&e, full_cmd, "-Wpedantic");
  vector_append(&e, full_cmd, "-Wextra");
  vector_append(&e, full_cmd, "-O3");
  vector_append(&e, full_cmd, "-g");
  vector_append(&e, full_cmd, "-fsanitize=address");
  vector_append(&e, full_cmd, "-o");
#elif defined(__GNUC__)
  vector_append(&e, full_cmd, "gcc");
  vector_append(&e, full_cmd, "-Wall");
  vector_append(&e, full_cmd, "-Wpedantic");
  vector_append(&e, full_cmd, "-Wextra");
  vector_append(&e, full_cmd, "-O3");
  vector_append(&e, full_cmd, "-g");
  vector_append(&e, full_cmd, "-fsanitize=address");
  vector_append(&e, full_cmd, "-o");
#else
  vector_append(&e, full_cmd, "cl");
  vector_append(&e, full_cmd, "/Wall");
  vector_append(&e, full_cmd, "/O2");
  vector_append(&e, full_cmd, "/Zi");
  vector_append(&e, full_cmd, "/fsanitize=address");
  vector_append(&e, full_cmd, "/Fe:");
#endif

  vector_append(&e, full_cmd, build_exe);
  vector_append(&e, full_cmd, (char *)build_file);
  vector_append(&e, full_cmd, NULL);

  printf("\tLD\t%s\n", build_exe);
  nobita_proc_append(b, e.full_cmd);
  nobita_proc_wait_all(b);
  e.full_cmd_used = 0;
  for (int i = 0; i < b->argc; i++)
    vector_append(&e, full_cmd, b->argv[i]);

  vector_append(&e, full_cmd, NULL);
  printf("\tCMD\t%s\n", e.full_cmd[0]);
  nobita_proc_append(b, e.full_cmd);
  nobita_proc_wait_all(b);

  vector_free(&e, full_cmd);
  b->was_self_rebuilt = true;
}

void Nobita_Target_Add_Headers(struct nobita_target *t, const char *parent,
                               ...) {
  if (nobita_build_failed)
    return;

  if (parent == NULL) {
    nobita_build_failed = true;
    fprintf(stderr,
            "When adding header files to a target, the parent "
            "dir should not be NULL (target: %s)\n",
            t->name);

    return;
  }

  struct nobita_header h;
  h.parent = (char *)parent;

  va_list va;
  va_start(va, parent);
  char *arg = va_arg(va, char *);
  while (arg != NULL) {
    h.header = arg;
    vector_append(t, headers, h);
    arg = va_arg(va, char *);
  }

  va_end(va);
}

char *Nobita_GetCwd(Nobita_Build *b) { return b->cwd; }

char *Nobita_GetCed(Nobita_Build *b) { return b->ced; }

char *Nobita_GetPrefix(Nobita_Build *b) { return b->prefix; }

char *Nobita_GetInclude(Nobita_Build *b) { return b->include; }

char *Nobita_GetBin(Nobita_Build *b) { return b->bin; }

char *Nobita_GetLib(Nobita_Build *b) { return b->lib; }

static struct nobita_target *nobita_build_add_target(struct nobita_build *b,
                                                     const char *name) {
  if (nobita_build_failed)
    return NULL;

  if (name == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "A target's name should not be NULL\n");
    return NULL;
  }

  struct nobita_target *t = calloc(1, sizeof(*t));
  if (t == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "Could not create target %s\n", name);
    return NULL;
  }

  t->name = (char *)name;

  vector_init(t, cflags);
  vector_init(t, sources);
  vector_init(t, objects);
  vector_init(t, ldflags);
  vector_init(t, full_cmd);
  vector_init(t, custom_cmd);
  vector_init(t, headers);
  vector_init(t, deps);

  vector_append(b, deps, t);
  t->b = b;
  return t;
}

static nobita_pid nobita_proc_exec(char **cmd, char *joined_cmd) {
  nobita_pid id = (nobita_pid)-1;
  if (nobita_build_failed)
    return id;

#ifndef _WIN32
  id = fork();
  if (id == -1) {
    nobita_build_failed = true;
    fprintf(stderr, "Creating the process\n'%s'\nFailed!\n", joined_cmd);
    return id;
  }

  if (id == 0) {
    execvp(*cmd, cmd);
    exit(errno);
  } else {
    return id;
  }
#else
  STARTUPINFO s = {0};
  PROCESS_INFORMATION p = {0};
  s.cb = sizeof(s);

  if (!CreateProcessA(NULL, joined_cmd, NULL, NULL, false, 0, NULL, NULL, &s,
                      &p)) {
    nobita_build_failed = true;
    fprintf(stderr, "Creating the process\n'%s'\nFailed!\n", joined_cmd);
    return id;
  } else
    return p.hProcess;
#endif /* _WIN32 */
}

static int nobita_proc_wait(nobita_pid pid, bool pause) {
  int status = -1;
#ifndef _WIN32
  waitpid(pid, &status, (pause) ? 0 : WNOHANG);
#else
  status = WaitForSingleObject(pid, (pause) ? INFINITE : 0);
#endif /* _WIN32 */
  return status;
}

static void nobita_proc_append(struct nobita_build *b, char **cmd) {
  if (nobita_build_failed)
    return;

  if (b->proc_queue_used >= nobita_max_proc_count)
    nobita_proc_wait_one(b);

  if (nobita_build_failed)
    return;

  char *c = nobita_strjoinv(" ", cmd);
  if (c == NULL)
    nobita_build_failed = true;

  nobita_pid pid = nobita_proc_exec(cmd, c);
  vector_append(b, proc_queue, pid);
  vector_append(b, proc_names, c);

  if (nobita_build_failed)
    free(c);
}

static void nobita_proc_wait_one(struct nobita_build *b) {
  bool continue_loop = !nobita_build_failed;
  while (continue_loop) {
    for (size_t i = 0; i < b->proc_queue_used; i++) {
      int status = nobita_proc_wait(b->proc_queue[i], false);
#ifndef _WIN32
      if (status != -1 && WIFEXITED(status)) {
#else
      if (status != WAIT_FAILED && status == WAIT_OBJECT_0) {
        CloseHandle(b->proc_queue[i]);
#endif /* _WIN32 */
        b->proc_queue[i] = b->proc_queue[b->proc_queue_used - 1];
        b->proc_queue_used -= 1;

#ifndef _WIN32
        if (WEXITSTATUS(status) != EXIT_SUCCESS) {
#else
        if (status == WAIT_FAILED) {
#endif /* _WIN32 */
          nobita_build_failed = true;
          fprintf(stderr, "A process did not exit sucessfully, marking "
                          "build as failed\n");

          fprintf(stderr, "Cmd: %s\n", b->proc_names[i]);
        }

        free(b->proc_names[i]);
        b->proc_names[i] = b->proc_names[b->proc_names_used - 1];
        b->proc_names_used -= 1;
        continue_loop = false;
        break;
      }
    }
  }
}

static void nobita_proc_wait_all(struct nobita_build *b) {
  for (size_t i = 0; i < b->proc_queue_used; i++) {
    int status = nobita_proc_wait(b->proc_queue[i], true);
#ifndef _WIN32
    if (!WIFEXITED(status) && !nobita_build_failed) {
      nobita_build_failed = true;
      fprintf(stderr, "A process did not exit\n");
      fprintf(stderr, "Cmd: %s\n", b->proc_names[i]);
    }

    if (WEXITSTATUS(status) != EXIT_SUCCESS && !nobita_build_failed) {
      nobita_build_failed = true;
      fprintf(stderr, "A process did not exit successfully\n");
      fprintf(stderr, "Cmd: %s\n", b->proc_names[i]);
    }
#else
    if (status == WAIT_FAILED && !nobita_build_failed) {
      nobita_build_failed = true;
      fprintf(stderr, "A process did not exit\n");
      fprintf(stderr, "Cmd: %s\n", b->proc_names[i]);
    }

    if (status != WAIT_OBJECT_0 && !nobita_build_failed) {
      nobita_build_failed = true;
      fprintf(stderr, "A process did not exit successfully\n");
      fprintf(stderr, "Cmd: %s\n", b->proc_names[i]);
    }

    CloseHandle(b->proc_queue[i]);
#endif /* _WIN32 */

    free(b->proc_names[i]);
  }

  b->proc_queue_used = 0;
  b->proc_names_used = 0;
}

static void nobita_mkdir_recursive(const char *path) {
  if (nobita_build_failed)
    return;

  char *p2 = nobita_strdup(path);
  if (p2 == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "Could not copy path '%s' for mkdir recursive\n", path);
    return;
  }

  size_t len = strlen(p2);
  for (size_t i = 1; i < len; i++) {
    if (p2[i] == *NOBITA_PATHSEP) {
      p2[i] = 0;

      if (!nobita_dir_exist(p2)) {
        printf("\tMKDIR\t%s\n", p2);
        mkdir(p2, 0777);
      }

      p2[i] = *NOBITA_PATHSEP;
    }
  }

  if (!nobita_dir_exist(p2)) {
    printf("\tMKDIR\t%s\n", p2);
    mkdir(p2, 0777);
  }

  free(p2);
}

static bool nobita_is_a_newer(const char *a, const char *b) {
  if (!nobita_file_exist(b))
    return true;

#ifndef _WIN32
  struct stat s_a, s_b;
  memset(&s_a, 0, sizeof(s_a));
  memset(&s_b, 0, sizeof(s_b));
  stat(a, &s_a);
  stat(b, &s_b);
  return (s_a.st_mtime > s_b.st_mtime);
#else
  WIN32_FILE_ATTRIBUTE_DATA s_a, s_b;
  memset(&s_a, 0, sizeof(s_a));
  memset(&s_b, 0, sizeof(s_b));
  GetFileAttributesExA(a, GetFileExInfoStandard, &s_a);
  GetFileAttributesExA(b, GetFileExInfoStandard, &s_b);
  return CompareFileTime(&s_a.ftLastWriteTime, &s_b.ftLastWriteTime) == 1;
#endif /* _WIN32 */
}

static bool nobita_file_exist(const char *path) {
#ifndef _WIN32
  struct stat buf;
  if (stat(path, &buf) == -1)
    return false;

  return !S_ISDIR(buf.st_mode);
#else
  WIN32_FILE_ATTRIBUTE_DATA s;
  memset(&s, 0, sizeof(s));
  if (GetFileAttributesExA(path, GetFileExInfoStandard, &s) == 0)
    return false;

  return !(s.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
#endif /* _WIN32 */
}

static bool nobita_dir_exist(const char *path) {
#ifndef _WIN32
  struct stat buf;
  if (stat(path, &buf) == -1)
    return false;

  return S_ISDIR(buf.st_mode);
#else
  WIN32_FILE_ATTRIBUTE_DATA s;
  memset(&s, 0, sizeof(s));
  if (GetFileAttributesExA(path, GetFileExInfoStandard, &s) == 0)
    return false;

  return (s.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
#endif /* _WIN32 */
}

static bool nobita_build_objects(struct nobita_target *t) {
  bool rebuild = false;
  for (size_t i = 0; i < t->objects_used; i++) {
    if (!nobita_is_a_newer(t->objects[i], t->sources[i])) {
      vector_append(t, full_cmd, t->comp_opts.cc);
      vector_append_vector(t, full_cmd, t, cflags);

      switch (t->comp_opts.bt) {
      case NOBITA_BT_GCC:
      case NOBITA_BT_GPP:
      case NOBITA_BT_LLVM:
      case NOBITA_BT_LLVMPP:
        vector_append(t, full_cmd, t->comp_opts.to_exe);
        break;
      case NOBITA_BT_MSVC:
        vector_append(t, full_cmd, t->comp_opts.rename_obj);
        break;
      }

      vector_append(t, full_cmd, t->objects[i]);
      vector_append(t, full_cmd, t->comp_opts.to_obj);
      vector_append(t, full_cmd, t->sources[i]);
      vector_append(t, full_cmd, NULL);

      if (t->sources_used > 0) {
        printf("\tCC\t%s\n", t->objects[i]);
        nobita_proc_append(t->b, t->full_cmd);
      }

      t->full_cmd_used = 0;
      rebuild = true;
    }
  }

  nobita_proc_wait_all(t->b);
  return rebuild;
}

static void nobita_set_exe(struct nobita_target *t, const char *output) {
  switch (t->comp_opts.bt) {
  case NOBITA_BT_GCC:
  case NOBITA_BT_GPP:
  case NOBITA_BT_LLVM:
  case NOBITA_BT_LLVMPP:
  case NOBITA_BT_MSVC:
    vector_append(t, full_cmd, t->comp_opts.cc);
    vector_append_vector(t, full_cmd, t, cflags);
    vector_append(t, full_cmd, t->comp_opts.to_exe);
    vector_append(t, full_cmd, (char *)output);
    vector_append_vector(t, full_cmd, t, objects);
    vector_append_vector(t, full_cmd, t, ldflags);
    break;
  }
}

static void nobita_set_sharedlib(struct nobita_target *t, const char *output) {
  switch (t->comp_opts.bt) {
  case NOBITA_BT_GCC:
  case NOBITA_BT_GPP:
  case NOBITA_BT_LLVM:
  case NOBITA_BT_LLVMPP:
  case NOBITA_BT_MSVC:
    vector_append(t, full_cmd, t->comp_opts.cc);
    vector_append_vector(t, full_cmd, t, cflags);
    vector_append(t, full_cmd, t->comp_opts.to_lib);
    vector_append(t, full_cmd, t->comp_opts.to_exe);
    vector_append(t, full_cmd, (char *)output);
    vector_append_vector(t, full_cmd, t, objects);
    vector_append_vector(t, full_cmd, t, ldflags);
    break;
  }
}

static void nobita_set_staticlib(struct nobita_target *t, const char *output) {
  switch (t->comp_opts.bt) {
  case NOBITA_BT_GCC:
  case NOBITA_BT_GPP:
  case NOBITA_BT_LLVM:
  case NOBITA_BT_LLVMPP:
    vector_append(t, full_cmd, t->comp_opts.ar);
    vector_append(t, full_cmd, t->comp_opts.ar_opts);
    vector_append(t, full_cmd, (char *)output);
    vector_append_vector(t, full_cmd, t, objects);
    break;
  case NOBITA_BT_MSVC:
    Nobita_Target_Add_Fmt_Arg(t, NOBITA_T_CFLAGS, "%s%s", t->comp_opts.ar_opts,
                              output);

    vector_append(t, full_cmd, t->comp_opts.ar);
    vector_append(t, full_cmd, t->cflags[t->cflags_used - 1]);
    vector_append_vector(t, full_cmd, t, objects);
    break;
  }
}

static void nobita_build_target(struct nobita_target *t) {
  if (t->built || nobita_build_failed)
    return;

  bool rebuild = false;
  for (size_t i = 0; i < t->deps_used; i++) {
    nobita_build_target(t->deps[i]);
    rebuild = (!rebuild) ? ((struct nobita_target *)t->deps[i])->rebuilt : true;
  }

  nobita_proc_wait_all(t->b);

  if (t->target_type != NOBITA_EXECUTABLE) {
    for (size_t i = 0; i < t->headers_used; i++) {
      char *parent = t->headers[i].parent;
      char *header = t->headers[i].header;
      char *src = nobita_strjoinl(NOBITA_PATHSEP, parent, header, NULL);
      char *dest = nobita_strjoinl(NOBITA_PATHSEP, t->b->include, header, NULL);

      nobita_dirname(dest);
      nobita_mkdir_recursive(dest);
      *strchr(dest, 0) = *NOBITA_PATHSEP;

      if (nobita_is_a_newer(src, dest))
        nobita_cp(dest, src);

      free(src);
      free(dest);
    }
  }

  rebuild = nobita_build_objects(t);
  char *name = NULL;
  char *output = NULL;

  switch (t->target_type) {
  case NOBITA_EXECUTABLE: {
    name = nobita_strjoinl("", t->name, NOBITA_EXECUT_EXT, NULL);
    output = nobita_strjoinl(NOBITA_PATHSEP, t->b->bin, name, NULL);
    break;
  }
  case NOBITA_SHARED_LIB: {
    name = nobita_strjoinl("", "lib", t->name, NOBITA_SHARED_EXT, NULL);
    output = nobita_strjoinl(NOBITA_PATHSEP, t->b->lib, name, NULL);
    break;
  }
  case NOBITA_STATIC_LIB: {
    name = nobita_strjoinl("", "lib", t->name, NOBITA_STATIC_EXT, NULL);
    output = nobita_strjoinl(NOBITA_PATHSEP, t->b->lib, name, NULL);
    break;
  }
  case NOBITA_CUSTOM_CMD: {
    break;
  }
  }

  if (!rebuild)
    for (size_t i = 0; i < t->objects_used; i++)
      rebuild = (!rebuild) ? nobita_is_a_newer(t->objects[i], output) : true;

  if (!rebuild && t->target_type != NOBITA_CUSTOM_CMD)
    goto end;

  switch (t->target_type) {
  case NOBITA_EXECUTABLE: {
    nobita_set_exe(t, output);
    break;
  }
  case NOBITA_SHARED_LIB: {
    nobita_set_sharedlib(t, output);
    break;
  }
  case NOBITA_STATIC_LIB: {
    nobita_set_staticlib(t, output);
    break;
  }
  case NOBITA_CUSTOM_CMD: {
    vector_append_vector(t, full_cmd, t, custom_cmd);
    break;
  }
  }

  vector_append(t, full_cmd, NULL);
  if (t->sources_used > 0 || t->target_type == NOBITA_CUSTOM_CMD)
    nobita_proc_append(t->b, t->full_cmd);

  if (t->target_type == NOBITA_CUSTOM_CMD) {
    printf("\tCMD\t");
    for (size_t i = 0; i < t->full_cmd_used - 1; i++)
      printf("%s ", t->full_cmd[i]);

    printf("\n");
    nobita_proc_wait_all(t->b);
  } else {
    printf("\tLD\t%s\n", output);
  }

  t->rebuilt = true;
end:
  t->built = true;
  free(name);
  free(output);
}

static void nobita_cp(const char *dest, const char *src) {
  if (nobita_build_failed)
    return;

  FILE *d = fopen(dest, "w");
  if (d == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "Failed to open dest file '%s' in copying\n", dest);
    return;
  }

  FILE *s = fopen(src, "r");
  if (s == NULL) {
    nobita_build_failed = true;
    fclose(d);
    fprintf(stderr, "Failed to open source file '%s' in copying\n", src);
    return;
  }

  char buf[4096];
  printf("\tCP\t%s\n", dest);
  while (true) {
    size_t read = fread(buf, sizeof(char), 4096, s);
    if (!read)
      break;

    size_t write = fwrite(buf, sizeof(char), read, d);
    if (read != write) {
      nobita_build_failed = true;
      fprintf(stderr,
              "Read and write counts for copying files %s -> %s did not "
              "match\n",
              src, dest);

      goto end;
    }
  }

end:
  fclose(d);
  fclose(s);
}

static char *nobita_strjoinl(const char *join, ...) {
  if (nobita_build_failed)
    return NULL;

  char *ret = NULL;
  size_t len = 1;

  char *arg = NULL;
  va_list va;
  va_start(va, join);
  arg = va_arg(va, char *);
  while (arg != NULL) {
    len += strlen(arg);
    arg = va_arg(va, char *);
    if (arg != NULL)
      len += strlen(join);
  }
  va_end(va);

  ret = malloc(len * sizeof(char));
  if (ret == NULL) {
    nobita_build_failed = true;
    fprintf(stderr,
            "Could not join strings using strjoinl as malloc returned NULL\n");

    return ret;
  }

  va_start(va, join);
  *ret = 0;
  arg = va_arg(va, char *);
  while (arg != NULL) {
    strcat(ret, arg);
    arg = va_arg(va, char *);
    if (arg != NULL)
      strcat(ret, join);
  }
  va_end(va);

  return ret;
}

static char *nobita_strjoinv(const char *join, char **v) {
  char *ret = NULL;
  char **v2 = v;
  size_t len = 1;
  while (*v != NULL) {
    len += strlen(*v);
    v++;
    if (*v != NULL)
      len += strlen(join);
  }

  ret = malloc(len);
  if (ret == NULL) {
    nobita_build_failed = true;
    fprintf(stderr,
            "Could not join strings using strjoinv as malloc returned NULL\n");

    return ret;
  }

  *ret = 0;
  while (*v2 != NULL) {
    strcat(ret, *v2);
    v2++;
    if (*v2 != NULL)
      strcat(ret, join);
  }

  return ret;
}

static char *nobita_getcwd(void) {
#ifndef _WIN32
  char *ret = getcwd(NULL, 0);
#else
  int len = GetCurrentDirectoryA(0, NULL);
  char *ret = malloc(len);
#endif /* _WIN32 */

  if (ret == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "Couldn't get current working directory\n");
  }

#ifdef _WIN32
  else {
    GetCurrentDirectoryA(len, ret);
  }
#endif

  return ret;
}

static char *nobita_getced(const char *argv0) {
  char *ret = NULL;
  char *exe = nobita_strdup(argv0);
  char *cwd = nobita_getcwd();
  nobita_dirname(exe);
  chdir(exe);
  ret = nobita_getcwd();
  chdir(cwd);
  free(exe);
  free(cwd);

  return ret;
}

static char *nobita_strdup(const char *s) {
  char *ret = malloc((strlen(s) + 1) * sizeof(char));
  if (ret == NULL) {
    nobita_build_failed = true;
    fprintf(stderr, "Could not duplicate a string as malloc returned NULL\n");
  } else {
    strcpy(ret, s);
  }

  return ret;
}

static void nobita_dirname(char *p) {
  char *s = strrchr(p, *NOBITA_PATHSEP);
  if (s == NULL) {
    p[0] = '.';
    p[1] = 0;
    return;
  }

  *s = 0;
}

int main(int argc, char **argv) {
  struct nobita_build b;
  char *prefix = NULL;
  if (argc >= 2) {
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      printf("nobita build usage: %s proc_count prefix\n", argv[0]);
      return EXIT_SUCCESS;
    } else {
      if (sscanf(argv[1], "%" SCNu64, &nobita_max_proc_count) != 1) {
        fprintf(stderr, "Invalid number for proc_count\n");
        printf("nobita build usage: %s proc_count prefix\n", argv[0]);
        return EXIT_FAILURE;
      }
    }
  }

  char *ced = nobita_getced(argv[0]);
  char *cwd = nobita_getcwd();
  if (argc >= 3) {
    if (strlen(argv[2]) == 0) {
      fprintf(stderr, "Invalid prefix length 0\n");
      printf("nobita build usage: %s proc_count prefix\n", argv[0]);
      free(ced);
      free(cwd);
      return EXIT_FAILURE;
    }

#ifndef _WIN32
    if (argv[2][0] != '/') {
      fprintf(stderr, "Invalid prefix (not an absolute path)\n");
      printf("nobita build usage: %s proc_count prefix\n", argv[0]);
      free(ced);
      free(cwd);
      return EXIT_FAILURE;
    }
#else
    if (argv[2][1] != ':' && argv[2][1] != '\\') {
      fprintf(stderr, "Invalid prefix (not an absolute path)\n");
      printf("nobita build usage: %s proc_count prefix\n", argv[0]);
      free(ced);
      free(cwd);
      return EXIT_FAILURE;
    }
#endif /* _WIN32 */

    prefix = nobita_strdup(argv[2]);
  } else {
    prefix = nobita_strjoinl(NOBITA_PATHSEP, cwd, "nobita-build", NULL);
  }

  char *include = nobita_strjoinl(NOBITA_PATHSEP, prefix, "include", NULL);
  char *bin = nobita_strjoinl(NOBITA_PATHSEP, prefix, "bin", NULL);
  char *lib = nobita_strjoinl(NOBITA_PATHSEP, prefix, "lib", NULL);

  printf("\tNOBITA\tPROC_COUNT = %" PRIu64 "\n", nobita_max_proc_count);
  printf("\tNOBITA\tCACHE_DIR  = %s%s%s\n", ced, NOBITA_PATHSEP,
         "nobita-cache");
  printf("\tNOBITA\tPREFIX_DIR = %s\n", prefix);
  printf("\tNOBITA\tINCLUDE_DIR= %s\n", include);
  printf("\tNOBITA\tBIN_DIR    = %s\n", bin);
  printf("\tNOBITA\tLIB_DIR    = %s\n", lib);

  nobita_mkdir_recursive(prefix);
  nobita_mkdir_recursive(bin);
  nobita_mkdir_recursive(lib);
  nobita_mkdir_recursive(include);

  vector_init(&b, deps);
  vector_init(&b, free_later);
  vector_init(&b, proc_queue);
  vector_init(&b, proc_names);

  b.argc = argc;
  b.argv = argv;
  b.was_self_rebuilt = false;

  b.ced = ced;
  b.cwd = cwd;
  b.prefix = prefix;
  b.include = include;
  b.bin = bin;
  b.lib = lib;

  build(&b);

  if (!b.was_self_rebuilt)
    for (size_t i = 0; i < b.deps_used; i++)
      nobita_build_target(b.deps[i]);

  for (size_t i = 0; i < b.deps_used; i++) {
    struct nobita_target *t = b.deps[i];
    for (size_t ii = 0; ii < t->objects_used; ii++) {
      free(t->sources[ii]);
      free(t->objects[ii]);
    }

    for (size_t ii = 0; ii < t->custom_cmd_used; ii++)
      free(t->custom_cmd[ii]);

    vector_free(t, cflags);
    vector_free(t, sources);
    vector_free(t, objects);
    vector_free(t, ldflags);
    vector_free(t, full_cmd);
    vector_free(t, custom_cmd);
    vector_free(t, headers);
    vector_free(t, deps);
    free(t);
  }

  nobita_proc_wait_all(&b);
  for (size_t i = 0; i < b.free_later_used; i++)
    free(b.free_later[i]);

  vector_free(&b, deps);
  vector_free(&b, free_later);
  vector_free(&b, proc_queue);
  vector_free(&b, proc_names);

  free(ced);
  free(cwd);
  free(prefix);
  free(include);
  free(bin);
  free(lib);
}

#endif /* NOBITA_IMPL */
