#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, key;

    do
    {
        printf("\nBinary Search Tree Operations:");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Inorder Traversal");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
            {
                printf("Element %d is found\n", key);
            }
            else
            {
                printf("Not found\n");
            }
            break;

        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
