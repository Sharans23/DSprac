#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct priorityQueue
{
    struct node *front;
};

struct node *createNode(int data, int priority)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}

struct priorityQueue *createPriorityQueue()
{
    struct priorityQueue *pq = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));
    pq->front = NULL;
    return pq;
}

int isEmpty(struct priorityQueue *pq)
{
    return (pq->front == NULL);
}

void enqueue(struct priorityQueue *pq, int data, int priority)
{
    struct node *newnode = createNode(data, priority);

    if (isEmpty(pq) || priority < pq->front->priority)
    {
        newnode->next = pq->front;
        pq->front = newnode;
    }
    else
    {
        struct node *temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int dequeue(struct priorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty");
        return -1;
    }
    else
    {
        struct node *temp = pq->front;
        int data = temp->data;
        pq->front = pq->front->next;
        free(temp);
        return data;
    }
}

void display(struct priorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty");
    }
    else
    {
        struct node *temp = pq->front;
        while (temp != NULL)
        {
            printf("(%d,%d)", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct priorityQueue *pq = createPriorityQueue();
    int choice, data, priority;
    do
    {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter data and priority to enqueue");
            scanf("%d %d", &data, &priority);
            enqueue(pq, data, priority);
            break;

        case 2:
            printf("Dequeued element is %d\n", dequeue(pq));
            break;

        case 3:
            printf("priority Queue");
            display(pq);
            break;

        case 4:
            printf("Exitingg");
            return -1;
        }
    } while (choice != 4);
    {
        return 0;
    }
}
