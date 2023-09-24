/*
 * Implement queue using linked list
 *
 */
#include <stdio.h>
#include <stdlib.h>

// declare Node structure
struct Node
{
    int data;
    struct Node *next;
};

// declare Queue structure
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// declare function to check if queue is full
int isFull()
{
    // try to create a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// declare function to check if queue is empty
int isEmpty(struct Queue *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// declare enqueue function
void enqueue(struct Queue *q, int data)
{
    // check if queue is full
    if (isFull())
    {
        printf("Queue is full");
        return;
    }
    else
    {
        // create a new node
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        if (q->front == NULL)
        {
            q->front = new_node;
            q->rear = new_node;
            printf("\n enqueued first element %d", data);
        }
        else
        {
            struct Node *temp = q->rear;
            temp->next = new_node;
            q->rear = new_node;
            printf("\n enqueued element %d", data);
        }
    }
}

// declare dequeue function
void dequeue(struct Queue *q)
{
    // check if queue is empty
    if (isEmpty(q))
    {
        printf("\n Queue is empty");
        return;
    }
    else
    {
        // get the front node
        struct Node *temp = q->front;
        q->front = q->front->next;
        printf("\n dequeued element %d", temp->data);

        // free the previous front node
        free(temp);
    }
}

int main()
{
    // create queue
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    dequeue(q);
    // enqueue
    enqueue(q, 10);
    enqueue(q, 20);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}
