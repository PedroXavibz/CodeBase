#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

/*
 * @brief the type of a value to be stored in a @ref Queue
 *      (void *) can be changed to int, long, or other types if needed.
 * */
typedef void *__Generic__;

typedef uint8_t i8;
typedef uint16_t i16;
typedef uint32_t i32;
typedef uint64_t i64;

#endif
