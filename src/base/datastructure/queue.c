#include "queue.h"
#include <stdlib.h>
#include <string.h>

// TODO: Erro handling
// TODO: Docs

Queue *queue_create(size_t data_size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL)
    return NULL;

  queue->front = queue->rear = NULL;
  queue->data_size = data_size;
  queue->length = 0;
  return queue;
}

void queue_free(Queue *queue) {
  if (queue == NULL)
    return;

  while (queue->front != NULL)
    queue_dequeue(queue);
  free(queue);
}

i8 queue_enqueue(Queue *queue, __Generic__ data) {
  if (queue == NULL || data == NULL)
    return 0;

  __QueueNode__ *node = (__QueueNode__ *)malloc(sizeof(__QueueNode__));
  if (node == NULL)
    return 0;

  node->data = malloc(queue->data_size);
  if (node->data == NULL) return 0;

  memcpy(node->data, data, queue->data_size);
  if (queue->front == NULL) {
    queue->front = node;
    queue->rear = node;
  } else {
    queue->rear->next = node;
    queue->rear = node;
  }

  queue->length++;
  return 1;
}

i8 queue_dequeue(Queue *queue) {
  if (queue == NULL || queue->front == NULL)
    return 0;

  __QueueNode__ *node = queue->front;
  queue->front = node->next;
  free(node->data);
  free(node);
  node = NULL;

  queue->length--;
  return 1;
}

static __Generic__ peek(Queue *queue, __QueueNode__ *node) {
  if (queue == NULL || node == NULL)
    return NULL;
  return node->data;
}

__Generic__ queue_peek_front(Queue *queue) { return peek(queue, queue->front); }

__Generic__ queue_peek_rear(Queue *queue) { return peek(queue, queue->rear); }

i8 queue_is_empty(Queue *queue) {
  if (queue == NULL || queue->length == 0)
    return 1;
  return 0;
}
