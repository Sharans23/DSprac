#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    printf("%d is popped", top->data);
    top = top->next;
    free(temp);
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice, value;
    while (1)
    {
        printf("Stack menu\n");
        printf("1. Push");
        printf("2. Pop");
        printf("3. Display");
        printf("4. Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting");
            return 0;
        }
    }
}
