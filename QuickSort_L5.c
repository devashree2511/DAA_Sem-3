#include <stdio.h>

void quicksort(int a[], int low, int high)
{
    int i, j, temp;

    if (low < high)
    {
        j = low;

        for (i = low; i < high; i++)
        {
            if (a[i] < a[high])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                j++;
            }
        }

        temp = a[j];
        a[j] = a[high];
        a[high] = temp;

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main()
{
    int a[20], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}