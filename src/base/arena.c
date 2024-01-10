#include "arena.h"
#include "types.h"
#include <stdlib.h>

Arena arena_init(size_t capacity) {
  __Generic__ data = malloc(sizeof(i8) * capacity);
  Arena arena = {
    .capacity = capacity,
    .size = 0,
    .data = data,
  };
  return arena;
}

void *arena_alloc(Arena *arena, size_t size) {
}
