// implementation of stack using array

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("stack is full\n");
        ;
    }
    else
    {
        stack[++top] = value;
        printf("element %d pushed into stack", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("element %d is popped from stack", stack[top--]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("stack elements are:");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("Stack Menu\n");
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
    return 0;
}
