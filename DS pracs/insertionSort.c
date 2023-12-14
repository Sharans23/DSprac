#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, min;
    int temp;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("After sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[1000];
    int n;

    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    return 0;
}