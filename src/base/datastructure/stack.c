#include "stack.h"
#include <stdlib.h>
#include <string.h>

// TODO: Erro handling
// TODO: Docs

Stack *stack_create(size_t data_size) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));

  stack->top = NULL;
  stack->lenght = 0;
  stack->data_size = data_size;
  return stack;
}

void stack_free(Stack *stack) {
  if (stack == NULL) return;

  while(stack->top != NULL)
    stack_pop(stack);
  free(stack);
}

i8 stack_push(Stack *stack, __Generic__ data) {
  if (stack == NULL || data == NULL)
    return 0;

  __Struct_Node__ *node = (__Struct_Node__ *)malloc(sizeof(__Struct_Node__));
  if (node == NULL)
    return 0;

  node->data = malloc(stack->data_size);
  if (node->data == NULL) return 0;
 
  memcpy(node->data, data, stack->data_size);
  if (stack->top == NULL) {
    stack->top = node;
  } else {
    stack->top->next = node;
    node->prev = stack->top;
    stack->top = node;
  }

  stack->lenght++;
  return 1;
}

i8 stack_pop(Stack *stack) {
  if (stack == NULL) return 0;

  __Struct_Node__ *node = stack->top;
  stack->top = node->prev;
  free(node->data);
  free(node);
  node = NULL;
  stack->lenght--;
  return 1;
}

__Generic__ stack_peek(Stack *stack) {
  if (stack == NULL || stack->top == NULL)
    return NULL;
  return stack->top->data;
}

i8 stack_is_empty(Stack *stack) {
  if (stack == NULL || stack->lenght == 0) return 1;
  return 0;
}
