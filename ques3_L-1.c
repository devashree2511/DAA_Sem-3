#include <stdio.h>

int main()
{
    int a[3], i, sum = 0;
    float average;

    printf("Enter 3 elements:\n");

    for(i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    average = (float)sum / 3;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f", average);

    return 0;
}