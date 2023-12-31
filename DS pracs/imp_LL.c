// implementation of linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start;

void create()
{
    int val;
    struct node *nn, *temp;
    if (start == NULL)
    {
        nn = (struct node *)malloc(sizeof(struct node));
        printf("enter the value\n");
        scanf("%d", &val);
        nn->data = val;
        nn->next = NULL;
        start = nn;
    }
    else
    {
        nn = (struct node *)malloc(sizeof(struct node));
        printf("enter valye\n");
        scanf("%d", &val);
        nn->data = val;
        nn->next = NULL;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void insert_beg()
{
    struct node *nn;
    int val;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d", &val);
    nn->data = val;
    nn->next = start;
    start = nn;
}

void insert_end()
{
    struct node *nn, *temp;
    int val;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d", &val);
    nn->data = val;
    nn->next = NULL;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}

void insert_after()
{
    struct node *nn, *temp;
    int val, x;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d", &val);
    nn->data = val;
    printf("enter the value after u want to insert data");
    scanf("%d", &x);
    temp = start;
    while (temp != NULL && temp->data != x)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        nn->next = temp->next;
        temp->next = nn;
    }
    else
    {
        printf("value not found");
    }
}

void insert_before()
{
    struct node *nn, *temp, *p;
    int x, val;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value you want to insert:\n");
    scanf("%d", &val);
    nn->data = val;
    printf("Enter the value before which u want to insert:\n");
    scanf("%d", &x);
    temp = start;
    while (temp != NULL && temp->data != x)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        if (temp == start)
        {
            nn->next = start;
            start = nn;
        }
        else
        {
            nn->next = temp;
            p->next = nn;
        }
    }
    else
    {
        printf("value founf\n");
    }
}

void delete()
{
    int val;
    struct node *temp, *p;
    printf("Enter the value you want to delete:");
    scanf("%d", &val);
    temp = start;
    while (temp != NULL && temp->data != val)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        if (temp == start)
        {
            start = start->next;
            free(temp);
        }
        else
        {
            p->next = temp->next;
            free(temp);
        }
    }
    else
    {
        printf("Not Found");
    }
}

void display()
{
    struct node *temp;
    temp = start;
    printf("Elements of LL:-");
    while (temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("Enter:\n 1.Create\n 2.Insert_beg\n 3.Insert_end\n 4.Insert_before\n 5.Insert_after\n 6. Delete\n 7.Display\n 0.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_before();
            break;
        case 5:
            insert_after();
            break;
        case 6:
            delete ();
            break;
        case 7:
            display();
            break;
        
        default:
            printf("Invalid Input!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
