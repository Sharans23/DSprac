#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff, power;
    struct Node *next;
} *start1,*start2,*start3;

struct Node *create()
{
    struct Node *start = NULL;
    int n, c, p;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the coefficient and power respectively:\n");
        scanf("%d %d", &c, &p);
        nn->coeff = c;
        nn->power = p;
        nn->next = NULL;
        if (start == NULL)
        {
            start = nn;
        }
        else
        {
            struct Node *temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    return start;
}

void addNode(int c, int p, struct Node **start)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->coeff = c;
    nn->power = p;
    nn->next = NULL;
    if (*start == NULL)
    {
        *start = nn;
    }
    else
    {
        struct Node *temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void polynomialOperation(int operationType)
{
    int n, c, p;
    struct Node *t1 = start1, *t2 = start2, *result = NULL;
    while (t1 != NULL || t2 != NULL)
    {
        if (t1 != NULL && (t2 == NULL || t1->power > t2->power))
        {
            addNode(operationType * t1->coeff, t1->power, &result);
            t1 = t1->next;
        }
        else if (t2 != NULL && (t1 == NULL || t1->power < t2->power))
        {
            addNode(operationType * t2->coeff, t2->power, &result);
            t2 = t2->next;
        }
        else
        {
            addNode(operationType * (t1->coeff - t2->coeff), t1->power, &result);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    start3 = result;
}

void display(struct Node *start)
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("(%d)x^(%d) ", temp->coeff, temp->power);
        if (temp->next != NULL)
        {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    start1 = create();
    start2 = create();
    printf("The first polynomial is: ");
    display(start1);
    printf("The second polynomial is: ");
    display(start2);

    do
    {
        printf("\nPolynomial Operations Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Display Result\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start3 = NULL;
            polynomialOperation(1);
            printf("Polynomial addition is: ");
            display(start3);
            break;

        case 2:
            start3 = NULL;
            polynomialOperation(-1);
            printf("Polynomial subtraction is: ");
            display(start3);
            break;

        case 3:
            printf("Resultant Polynomial: ");
            display(start3);
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
