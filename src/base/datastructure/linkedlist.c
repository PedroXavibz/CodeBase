#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void throw_error(const char *error, const char *function_name, int line) {
  fprintf(stderr, "\n%s: Error on function \"%s\", file \"%s\" at line %d \n", error, function_name, __FILE__, line);
  exit(EXIT_FAILURE);
}

static __LinkedList_Node__ *get_node_by_index(LinkedList *linkedlist, long int index) {
   if (index < 0)
    index = linkedlist->length - (index * -1);

  __LinkedList_Node__ *node = NULL;
  long int middle = (linkedlist->length - 1) / 2;

  if (index > middle) {
    index = (linkedlist->length - 1) - index;
    node = linkedlist->tail;
    for (int i = 0; i < index; i++)
      node = node->prev;
  } else {
    node = linkedlist->head;
    for (int i = 0; i < index; i++)
      node = node->next;
  }
  return node;
}

static __LinkedList_Node__ *create_node(__Generic__ data, size_t data_size) {
  __LinkedList_Node__ *node = malloc(sizeof(__LinkedList_Node__));
  if (node == NULL)
    throw_error("MallocError", __func__, __LINE__ - 2);

  node->data = malloc(data_size);
  if (node->data == NULL)
    throw_error("MallocError", __func__, __LINE__ - 2);

  memcpy(node->data, data, data_size);
  return node;
}

LinkedList *linkedlist_create(size_t data_size) {
  LinkedList *linkedlist = (LinkedList *)malloc(sizeof(LinkedList));
  if (linkedlist == NULL)
    throw_error("MallocError", __func__, __LINE__ - 2);

  linkedlist->head = linkedlist->tail = NULL;
  linkedlist->data_size = data_size;
  linkedlist->length = 0;
  return linkedlist;
}

// TODO: free
void linkedlist_free(LinkedList *linkedlist) {
  if (linkedlist == NULL)
    throw_error("InvalidArgs", __func__, __LINE__ - 2);
}

i8 linkedlist_append(LinkedList *linkedlist, __Generic__ data) {
  if (linkedlist == NULL || data == NULL)
    throw_error("InvalidArgs", __func__, __LINE__ - 2);

  __LinkedList_Node__ *node = create_node(data, linkedlist->data_size);
  if (linkedlist->head == NULL) {
    linkedlist->head = node;
    linkedlist->tail = node;
  } else {
    linkedlist->tail->next = node;
    node->prev = linkedlist->tail;
    linkedlist->tail = node;
  }
  linkedlist->length++;
  return 1;
}

i8 linkedlist_prepend(LinkedList *linkedlist, __Generic__ data) {
  if (linkedlist == NULL || data == NULL)
    throw_error("InvalidArgs", __func__, __LINE__ - 2);

  __LinkedList_Node__ *node = create_node(data, linkedlist->data_size);
  if (linkedlist->head == NULL) {
    linkedlist->head = node;
    linkedlist->tail = node;
  } else {
    linkedlist->head->prev = node;
    node->next = linkedlist->head;
    linkedlist->head = node;
  }
  linkedlist->length++;
  return 1;
}

i8 linkedlist_remove(LinkedList *linkedlist, __Generic__ data, i8 (*compare)(const void *, const void *)) {
  if (linkedlist == NULL || data == NULL || compare == NULL)
    throw_error("InvalidArgs", __func__, __LINE__ - 2);
  else if (linkedlist->head == NULL)
    throw_error("EmptyList", __func__, __LINE__ - 4);

  if (compare(linkedlist->head->data, data))
    linkedlist_remove_at(linkedlist, 0);
  else if(compare(linkedlist->tail->data, data))
    linkedlist_remove_at(linkedlist, linkedlist->length - 1);

  __LinkedList_Node__ *node = linkedlist->head;
  while(node) {
    if (compare(node->data, data)) {
      node->prev->next = node->next;
      free(node->data);
      free(node);
      node = NULL;
      return 1;
    }
    node = node->next;
  }
  return 0;
}

i8 linkedlist_remove_at(LinkedList *linkedlist, long int index) { 
  if (linkedlist == NULL)
    throw_error("InvalidArgs", __func__, __LINE__);
  else if (linkedlist->head == NULL)
    throw_error("EmptyList", __func__, __LINE__);
  else if ((index >= linkedlist->length) || (index < 0 && index * -1 >= linkedlist->length))
    throw_error("IndexOutOfBound", __func__, __LINE__ - 4);

  __LinkedList_Node__ *node = NULL;
  if (index == 0) {
    node = linkedlist->head;
    linkedlist->head = node->next;
  } else if (index == linkedlist->length - 1) {
    node = linkedlist->tail;
    linkedlist->tail = node->prev;
  } else {
    node = get_node_by_index(linkedlist, index);
    node->prev->next = node->next;
  }

  free(node->data);
  free(node);
  node = NULL;
  linkedlist->length--;
  return 1; 
}

long int linkedlist_index(LinkedList *linkedlist, __Generic__ data, i8 (compare)(const void *, const void *)) {
  if (linkedlist == NULL || data == NULL || compare == NULL)
    throw_error("InvalidArgs", __func__, __LINE__ - 2);
  else if (linkedlist->head == NULL)
    throw_error("EmptyList", __func__, __LINE__);

  if (compare(data, linkedlist->head->data))
    return 0;
  else if (compare(data, linkedlist->tail->data))
    return linkedlist->length - 1;

  __LinkedList_Node__ *head = linkedlist->head;
  __LinkedList_Node__ *tail = linkedlist->tail;
  long int index = 0;
  for (long int i = 0; i < linkedlist->length; i++) {
    if (compare(data, head->data)) {
      index = i;
      break;
    } else if (compare(data, tail->data)) {
      index = (linkedlist->length - 1) - i;
      break;
    }

    head = head->next;
    tail = tail->prev;
  }
  return index;
}

__Generic__ linkedlist_search(LinkedList *linkedlist, __Generic__ data, i8 (compare)(const void *, const void *)) {
  if (linkedlist == NULL || data == NULL || compare == NULL)
    throw_error("InvalidArgs", __func__, __LINE__);
  else if (linkedlist->head == NULL)
    throw_error("EmptyList", __func__, __LINE__);

  if (compare(data, linkedlist->head->data))
    return linkedlist->head->data;
  else if (compare(data, linkedlist->tail->data))
    return linkedlist->tail->data;

  __LinkedList_Node__ *head = linkedlist->head;
  __LinkedList_Node__ *tail = linkedlist->tail;
  __LinkedList_Node__ *node = NULL;
  for (long int i = 0; i < linkedlist->length; i++) {
    if (compare(data, head->data)) {
      node = head;
      break;
    } else if (compare(data, tail->data)) {
      node = tail;
      break;
    }

    head = head->next;
    tail = tail->prev;
  }
  return node->data;
}

__Generic__ linkedlist_get(LinkedList *linkedlist, long int index) {
  if (linkedlist == NULL)
    throw_error("InvalidArgs", __func__, __LINE__);
  else if (linkedlist->head == NULL) 
    throw_error("EmptyList", __func__, __LINE__ - 6);
  else if ((index >= linkedlist->length) || (index < 0 && index * -1 >= linkedlist->length))
    throw_error("IndexOutOfBound", __func__, __LINE__ - 4);
  if (index == 0)
    return linkedlist->head->data;
  else if (index == linkedlist->length - 1)
    return linkedlist->tail->data;
  
  __LinkedList_Node__ *node = get_node_by_index(linkedlist, index);
  return node->data;
}
