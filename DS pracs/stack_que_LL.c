#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack *stack, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack.\n", data);
}

int pop(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to queue.\n", data);
}

int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void display(struct Node *head, const char *label)
{
    printf("%s elements: ", label);
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Stack stack = {.top = NULL};
    struct Queue queue = {.front = NULL, .rear = NULL};

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    display(stack.top, "Stack");

    printf("%d popped from stack.\n", pop(&stack));
    printf("%d popped from stack.\n", pop(&stack));
    display(stack.top, "Stack");

    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    display(queue.front, "Queue");

    printf("%d dequeued from queue.\n", dequeue(&queue));
    printf("%d dequeued from queue.\n", dequeue(&queue));
    display(queue.front, "Queue");

    return 0;
}
