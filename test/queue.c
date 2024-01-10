#include "../src/base/datastructure/queue.h"
#include <stdio.h>

#define ARRAY_LEN(array) (sizeof(array) / sizeof((array)[0]))

static void print_node(__QueueNode__ *node) {
  printf("Data: %d | Current: %p | |  Next: %p\n", (*(int *)node->data), node,
         node->next);
}

static void print_queue(__QueueNode__ *front) {
  while (front != NULL) {
    print_node(front);
    front = front->next;
  }
}

static void empty_test(Queue *queue) {
  printf("\n[ IS EMPTY ]: %d\n", queue_is_empty(queue));
}

static void enqueue_test(Queue *queue, int values[], int len) {
  printf("\n[ ENQUEUE ]\n");
  for (int i = 0; i < len; i++)
    queue_enqueue(queue, &values[i]);
  print_queue(queue->front);
}

static void dequeue_test(Queue *queue, int amount) {
  printf("\n[ DENQUEUE ]\n");
  for (int i = 0; i < amount; i++)
    queue_dequeue(queue);
  print_queue(queue->front);
}

int main(int argc, char *argv[]) {
  Queue *queue_i = queue_create(sizeof(int));

  if (queue_i == NULL)
    return 1;

  int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t len = sizeof(values) / sizeof(values[0]);

  enqueue_test(queue_i, values, len);
  printf("[ LENGHT ]: %ld\n", queue_i->length);

  empty_test(queue_i);

  dequeue_test(queue_i, 3);
  printf("[ LENGHT ]: %ld\n", queue_i->length);

  printf("\n[ FRONT ]: %d\n", *(int *)queue_peek_front(queue_i));
  printf("[ REAR ]: %d\n", *(int *)queue_peek_rear(queue_i));

  queue_free(queue_i);
  printf("\n[ FREE QUEUE ]\n");

  empty_test(queue_i);
  printf("\n[ LENGHT ]: %ld\n", queue_i->length);
}
