#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../types.h"
#include <stddef.h>

typedef struct _LLN_T {
  __Generic__ data;
  struct _LLN_T *next;
  struct _LLN_T *prev;
} __LinkedList_Node__;

typedef struct {
  __LinkedList_Node__ *head;
  __LinkedList_Node__ *tail;
  size_t data_size;
  long int length;
} LinkedList;

LinkedList *linkedlist_create(size_t data_size);

void linkedlist_free(LinkedList *linkedlist);

i8 linkedlist_append(LinkedList *linkedlist, __Generic__ data);

i8 linkedlist_prepend(LinkedList *linkedlist, __Generic__ data);

i8 linkedlist_remove(LinkedList *linkedlist, __Generic__ data, i8 (*compare)(const void *, const void *));

i8 linkedlist_remove_at(LinkedList *linkedlist, long int index);

long int linkedlist_index(LinkedList *linkedlist, __Generic__ data, i8 (*compare)(const void *, const void *));

__Generic__ linkedlist_search(LinkedList *linkedlist, __Generic__ data, i8 (*compare)(const void *, const void *));

__Generic__ linkedlist_get(LinkedList *linkedlist, long int index);

#endif
