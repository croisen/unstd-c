#ifndef _STDINT_H
#define _STDINT_H

typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef signed long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

typedef int64_t int_least8_t;
typedef int64_t int_least16_t;
typedef int64_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint64_t uint_least8_t;
typedef uint64_t uint_least16_t;
typedef uint64_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int64_t int_fast8_t;
typedef int64_t int_fast16_t;
typedef int64_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint64_t uint_fast8_t;
typedef uint64_t uint_fast16_t;
typedef uint64_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef int64_t intptr_t;
typedef uint64_t uintptr_t;

typedef int64_t intmax_t;
typedef uint64_t uintmax_t;

#define INT8_MIN -127L
#define INT16_MIN -32767L
#define INT32_MIN -2147483647L
#define INT64_MIN -9223372036854775807L

#define INT8_MAX (127L)
#define INT16_MAX (32767L)
#define INT32_MAX (2147483647L)
#define INT64_MAX (9223372036854775807L)

#define UINT8_MIN (0UL)
#define UINT16_MIN (0UL)
#define UINT32_MIN (0UL)
#define UINT64_MIN (0UL)

#define UINT8_MAX (127UL)
#define UINT16_MAX (65535UL)
#define UINT32_MAX (4294967295UL)
#define UINT64_MAX (18446744073709551615UL)

#endif /* _STDINT_H */
