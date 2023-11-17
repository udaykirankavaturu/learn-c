// implement a queue data structure
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int back;
    int size;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->back == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->front == q->back)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int data)
{
    // check if queue is full
    if (isFull(q))
    {
        printf("\n Queue is full.");
        return;
    }
    else
    {
        q->back++;
        q->arr[q->back] = data;
        printf("\n %d element added to queue", data);
        return;
    }
}

void dequeue(struct queue *q)
{
    // check if queue is empty
    if (isEmpty(q))
    {
        printf("\n Queue is empty.");
        return;
    }
    else
    {
        q->front++;
        printf("\n %d element removed from queue", q->arr[q->front]);
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = -1;
    q->back = -1;
    q->size = 1;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    enqueue(q, 10);
    enqueue(q, 10);
    dequeue(q);
    dequeue(q);

    return 0;
}