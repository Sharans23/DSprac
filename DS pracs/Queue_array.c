//implementation of queue using array
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("%d dequeued", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue elements are");
        for (int i = front; i <= rear; i++)
        {
            printf("%d", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, value;
    while (1)
    {
        printf("queue menu");
        printf("1. Enqueue");
        printf("2. Dequeue");
        printf("3. Display");
        printf("4. Exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("value to be inserted in queue");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting....");
            return 0;
        }
    }
}
