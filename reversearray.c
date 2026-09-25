#include <stdio.h>

int main()
{
    int a[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Reversed array: ");
    for(int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    return 0;
}