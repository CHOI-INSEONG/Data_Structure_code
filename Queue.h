#include <stdio.h>
#define MAX_QUEUE 5

typedef enum{true, false} bool;
typedef int Data;

typedef struct {
    int rear;
    int front;
    Data items[MAX_QUEUE];
}Queue;

void InitQueue(Queue* queue) {
    queue->front = queue->rear = 0;
}

bool IsFull(Queue* queue) {
    return queue->front == (queue->rear + 1) % MAX_QUEUE;
}

bool IsEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

Data peek(Queue* queue) {
    if (IsEmpty(queue)) {
        exit(1);
    }
    else {
        return queue->items[queue->front];
    }
}

void EnQueue(Queue* queue, Data item){
    if (IsFull(queue)) {
        exit(1);
    }
    else {
        queue->items[queue->rear] = item;
        queue->rear = (queue->rear + 1) % MAX_QUEUE;
    }
}

void DeQueue(Queue* queue) {
    if (IsEmpty(queue)) {
        exit(1);
    }
    else {
        queue->front = (queue->front + 1) % MAX_QUEUE;
    }
}