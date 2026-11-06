#include <stdio.h>

int main()
{
    int n, capacity;
    float weight[20], profit[20], ratio[20];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    float totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            capacity -= weight[i];
            totalProfit += profit[i];
        }
        else
        {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}