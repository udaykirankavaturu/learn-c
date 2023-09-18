#include <stdio.h>
#include <stdlib.h>

// creating a stack data structure using linked lists

// create a linked list node structure
struct Node
{
    int data;
    struct Node *next;
};

// create a stack structure
struct Stack
{
    int top;
    int size;
    struct Node *head;
};

int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// push to stack
void push(struct Stack *s, int data)
{
    // create a new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // check if stack is empty
    if (s->head == NULL)
    {
        printf("\n stack is empty, adding first node with data %d..", data);
        s->head = new_node;
        s->top++;
    }
    else
    {
        // check if stack is full
        if (isFull(s))
        {
            printf("\n STACK OVERFLOW!");
        }
        else
        {
            printf("\n stack is not full, adding data %d at the start of the list..", data);

            //  make new node as head
            new_node->next = s->head;
            s->head = new_node;
            s->top++;
            printf("\n node added to the stack successfully!");
        }
    }
}

void pop(struct Stack *s)
{
    // check if stack is empty
    if (isEmpty(s))
    {
        printf("\n stack is empty, nothing to pop!");
    }
    else
    {

        struct Node *prev_node = NULL;
        struct Node *ptr = s->head;

        // move head to next node and free it
        s->head = s->head->next;
        printf("\n popped value %d", ptr->data);
        free(ptr);
        s->top--;
    }
}

void show(struct Stack *s)
{
    // check if stack is empty
    if (s->head == NULL)
    {
        printf("\n stack is empty, nothing to show!");
        return;
    }
    else
    {
        printf("\n stack is not empty, showing stack contents..");
        // traverse through the stack nodes
        struct Node *ptr = s->head;
        do
        {
            printf("\n stack element is: %d", ptr->data);
            ptr = ptr->next;
        } while (ptr != NULL);
    }
}

void peek(struct Stack *s, int position)
{
    struct Node *ptr = s->head;
    // traverse until position
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }

    // check if end of list is reached
    if (ptr == NULL)
    {
        printf("\n reached the end of the stack!");
        return;
    }
    else
    {
        printf("\n element found at position %d", ptr->data);
    }
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = 10;
    s->head = NULL;

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    push(s, 70);
    push(s, 80);
    push(s, 90);
    push(s, 100);
    push(s, 110);
    pop(s);
    show(s);
    peek(s, 2);

    return 0;
}