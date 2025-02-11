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

#define smin(count) -(2LL << (count - 1))
#define smax(count) (2LL << (count - 1)) - 1
#define umin(count) 0
#define umax(count) ((2LU << (count - 1)) - 1

#define INT8_MIN smin(8)
#define INT16_MIN smin(16)
#define INT32_MIN smin(32)
#define INT64_MIN smin(64)

#define INT8_MAX smax(8)
#define INT16_MAX smax(16)
#define INT32_MAX smax(32)
#define INT64_MAX smax(64)

#define UINT8_MIN umin(8)
#define UINT16_MIN umin(16)
#define UINT32_MIN umin(32)
#define UINT64_MIN umin(64)

#define UINT8_MAX umax(8)
#define UINT16_MAX umax(16)
#define UINT32_MAX umax(32)
#define UINT64_MAX umax(64)

#endif /* _STDINT_H */
