#include <stdio.h>

int main() {
    int arr[] = {3, 4, 5, 2};
    int n = 4;
    int sum = 9;

    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= sum; j++) {

            if (arr[i-1] <= j) {
                dp[i][j] =
                    dp[i-1][j] ||
                    dp[i-1][j-arr[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if (dp[n][sum])
        printf("Subset exists");
    else
        printf("Subset does not exist");

    return 0;
}