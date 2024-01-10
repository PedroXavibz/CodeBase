#ifndef QUEUE_H
#define QUEUE_H

#include "../types.h"
#include <stddef.h>

typedef struct _QN_T {
  __Generic__ data;
  struct _QN_T *next;
} __QueueNode__;

typedef struct {
  __QueueNode__ *front;
  __QueueNode__ *rear;
  size_t data_size;
  size_t length;
} Queue;

Queue *queue_create(size_t data_size);

void queue_free(Queue *queue);

i8 queue_enqueue(Queue *queue, __Generic__ data);

i8 queue_dequeue(Queue *queue);

__Generic__ queue_peek_front(Queue *queue);

__Generic__ queue_peek_rear(Queue *queue);

i8 queue_is_empty(Queue *queue);

#endif
