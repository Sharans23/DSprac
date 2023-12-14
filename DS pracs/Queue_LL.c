#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        front = front->next;
        free(temp);
    }
}

void main()
{
    int choice, val;
    while (1)
    {
        printf("queue menu");
        printf("1. Enqueue");
        printf("2. Dequeue");                   
        printf("3. Display");
        printf("4. Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("element to be pushed");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting...");
            return 0;
        }
    }
}
