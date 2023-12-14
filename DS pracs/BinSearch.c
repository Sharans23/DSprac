#include <stdio.h>

int BinarySearch()
{

    int a[1000];
    int n;
    int key;
    printf("enter no of components");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter elements");
        scanf("%d", &a[i]);
    }
    printf("Element you want to search:");
    scanf("%d", &key);

    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

void main(mid)
{

    int searchIndex = BinarySearch();

    if (searchIndex == -1)
    {
        printf("element not found");
    }
    else
    {
        printf("found at %d", searchIndex);
    }
}