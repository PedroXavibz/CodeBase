#ifndef STACK_H
#define STACK_H

#include "../types.h"
#include <stddef.h>

typedef struct _SN_T {
  __Generic__ data;
  struct _SN_T *next;
  struct _SN_T *prev;
} __Struct_Node__ ;

typedef struct {
  __Struct_Node__ *top;
  size_t data_size;
  size_t lenght;
} Stack;

Stack *stack_create(size_t data_size);

void stack_free(Stack *stack);

i8 stack_push(Stack *stack, __Generic__ data);

i8 stack_pop(Stack *stack);

__Generic__ stack_peek(Stack *stack);

i8 stack_is_empty(Stack *stack);

#endif
