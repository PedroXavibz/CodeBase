#include "./base/datastructure/linkedlist.h"
#include "./base/helper.h"
#include <stdio.h>

static void print_node(__LinkedList_Node__ *node, int i) {
  printf("[%d] Data: %d | Current: %p | Prev: %p | Next: %p\n", i,
         (*(int *)node->data), node, node->prev, node->next);
}

static void print_linkedlist(__LinkedList_Node__ *head) {
  int i = 0;
  while (head != NULL) {
    print_node(head, i);
    i++;
    head = head->next;
  }
}

static void append_test(LinkedList *ll, int values[], size_t len) {
  printf("\n[ APPEND ]\n");
  for (size_t i = 0; i < len; i++) {
    linkedlist_append(ll, &values[i]);
  }
  print_linkedlist(ll->head);
}

static void prepend_test(LinkedList *ll, int values[], size_t len) {
  printf("\n[ PREPEND ]\n");
  for (size_t i = 0; i < len; i++) {
    linkedlist_prepend(ll, &values[i]);
  }
  print_linkedlist(ll->head);
}

static void get_test(LinkedList *ll, long int i) {
  printf("[ GET %ld ]:  %d\n", i, *(int *)linkedlist_get(ll, i));
}

static void remove_at_test(LinkedList *ll, long int i) {
  printf("\n[ REMOVE AT %ld ]\n", i);
  linkedlist_remove_at(ll, i);
  print_linkedlist(ll->head);
}

static i8 compare(const void *a, const void *b) {
  if (*(int *)a == *(int *)b)
    return 1;
  return 0;
}

static void index_test(LinkedList *ll, void *target) {
  int value = *(int *)target;
  long int index = linkedlist_index(ll, target, compare);
  printf("\n[ Index of the Value %d | Index %ld ]\n", value, index);
}

static void search_test(LinkedList *ll, void *target) {
  int value = *(int *) linkedlist_search(ll, target, compare);
  printf("\n[ Search Value %d ]\n", value);
}

static void remove_test(LinkedList *ll, void *target) {
  printf("\n[ REMOVE %d ]\n", *(int *)target);
  linkedlist_remove(ll, target, compare);
  print_linkedlist(ll->head);
}

int main(int argc, char *argv[]) {
  LinkedList *ints = linkedlist_create(sizeof(int));

  int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
  size_t len = ARRAY_LEN(values);

  int values2[] = {9, 10, 11, 12};
  size_t len2 = ARRAY_LEN(values2);

  append_test(ints, values, len);
  printf("[ LENGTH ]: %ld\n", ints->length);

  prepend_test(ints, values2, len2);
  printf("[ LENGTH ]: %ld\n", ints->length);

  printf("\n[ GET + ]\n");
  for (int i = 0; i < len + len2; i++)
    get_test(ints, i);

  printf("\n[ GET - ]\n");
  for (int i = 0; i < len + len2; i++)
    get_test(ints, i * -1);

  index_test(ints, &values[3]);

  search_test(ints, &values[4]);

  remove_at_test(ints, 0);
  remove_at_test(ints, 3);

  remove_test(ints, linkedlist_get(ints, 5));

  linkedlist_free(ints);
}
