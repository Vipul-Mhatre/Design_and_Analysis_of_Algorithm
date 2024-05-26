
#include <stdio.h>
#include <conio.h>
#include <limits.h>

int i,j;
int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int coins[], int n, int sum) {
    int dp[100];
    for (i = 0; i <= sum; i++) {
	dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (i = 0; i < n; i++) {
	for (j = coins[i]; j <= sum; j++) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }
    }
    return (dp[sum] == INT_MAX) ? -1 : dp[sum];
}

void main() {
    int coins[100], n, sum,result;
    clrscr();
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the denominations of coins:\n");
    for (i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
    printf("Enter the sum to make: ");
    scanf("%d", &sum);
     result = minCoins(coins, n, sum);
    if (result == -1) {
        printf("It is not possible to make the sum using the given coins.\n");
    } else {
	printf("Minimum number of coins required to make %d: %d\n", sum, result);
    }
    getch();
}