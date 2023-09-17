#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *reverseLinkedList(struct Node *node)
{
    struct Node *prevNode = NULL;
    struct Node *currentNode = node;
    struct Node *nextNode = NULL;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}

void insertNodeAfter(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = head->next;
    head->next = newNode;
}

void deleteNodeAfter(struct Node *head)
{
    struct Node *nextNode = head->next;

    head->next = nextNode->next;
    free(nextNode);
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    printf("before reversing the linked list\n");
    linkedListTraversal(head);
    struct Node *newHead = reverseLinkedList(head);
    printf("after reversing the linked list\n");
    linkedListTraversal(newHead);

    printf("inserting a node at the beginning\n");
    insertNodeAfter(newHead, 60);

    printf("after inserting a node at the beginning\n");
    linkedListTraversal(newHead);

    deleteNodeAfter(newHead);
    printf("after deleting head node\n");
    linkedListTraversal(newHead);

    return 0;
}