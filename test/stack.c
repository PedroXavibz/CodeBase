#include "../src/base/datastructure/stack.h"
#include <stdio.h>

static void print_node(__Struct_Node__ *node) {
  printf("Data: %d | Current: %p | Prev: %p\n", (*(int *)node->data), node,
         node->prev);
}

static void print_stack(__Struct_Node__ *top) {
  while (top != NULL) {
    print_node(top);
    top = top->prev;
  }
}

static void empty_test(Stack *stack) {
  printf("\n[ IS EMPTY ]: %d\n", stack_is_empty(stack));
}

static void push_test(Stack *stack, int values[], int len) {
  printf("\n[ PUSH ]\n");
  for (int i = 0; i < len; i++)
    stack_push(stack, &values[i]);
  print_stack(stack->top);
}

static void pop_test(Stack *stack, int amount) {
  printf("\n[ POP ]\n");
  for (int i = 0; i < amount; i++)
    stack_pop(stack);
  print_stack(stack->top);
}

int main(int argc, char *argv[]) {
  Stack *stack_i = stack_create(sizeof(int));

  int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int len = sizeof(values) / sizeof(values[0]);

  push_test(stack_i, values, len);
  printf("[ LENGHT ]: %ld\n", stack_i->lenght);
  empty_test(stack_i);

  pop_test(stack_i, 3);
  printf("[ LENGHT ]: %ld\n", stack_i->lenght);

  printf("\n[ TOP ]: %d \n", *(int *)stack_peek(stack_i));

  printf("\n[ STACK FREE ]\n");
  stack_free(stack_i);
  empty_test(stack_i);
}
