// implement circular queue data structure
#include <stdio.h>
#include <stdlib.h>

// create circular queue structure
struct circularQueue
{
    int front;
    int back;
    int size;
    int *arr;
};

// isFull function
int isFull(struct circularQueue *q)
{
    if ((q->back + 1) % (q->size) == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isEmpty function
int isEmpty(struct circularQueue *q)
{
    if (q->back == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// enqueue function
void enqueue(struct circularQueue *q, int data)
{
    // check if queue is full
    if (isFull(q))
    {
        printf("\n Queue is full!");
    }
    else
    {
        q->back = (q->back + 1) % (q->size);
        q->arr[q->back] = data;
        printf("\n Enqueued element: %d", data);
    }
}

// dequeue function
void dequeue(struct circularQueue *q)
{
    // check if queue is empty
    if (isEmpty(q))
    {
        printf("\n Queue is empty!");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        printf("\n Dequeued element: %d", q->arr[q->front]);
        q->arr[q->front] = 0;
    }
}

int main()
{

    // create circular queue
    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->front = 0;
    q->back = 0;
    q->size = 6;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("\n back value is %d", q->back);
    printf("\n front value is %d", q->front);
    enqueue(q, 70);
    dequeue(q);

    printf("\n back value is %d", q->back);
    printf("\n front value is %d", q->front);

    return 0;
}