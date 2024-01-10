#ifndef ARENA_H
#define ARENA_H

#include "./types.h"
#include <stddef.h>

typedef struct {
  size_t capacity;
  size_t size;
  i8 *data;
} Arena;

Arena arena_init(size_t capacity);

void *arena_alloc(Arena *arena, size_t size);

#endif
