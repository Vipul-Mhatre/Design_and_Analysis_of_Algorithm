#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    int amount, n,i,coinCount,j;
    int *coins = (int *)malloc(n * sizeof(int));
    clrscr();
    printf("Enter the total amount: ");
    scanf("%d", &amount);

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    if (coins == NULL) {
	printf("Memory allocation failed\n");
	return 1;
    }

    printf("Enter the denominations of coins:\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &coins[i]);
    }

    for (i = 0; i < n; i++) {
	for (j = i + 1; j < n; j++) {
	    if (coins[j] < coins[i]) {
		int temp = coins[j];
		coins[j] = coins[i];
		coins[i] = temp;
	    }
	}
    }

     coinCount = 0;

    printf("Coins used: ");
    for (i = n - 1; i >= 0; i--) {
	while (amount >= coins[i]) {
	    amount -= coins[i];
	    coinCount++;
	    printf("%d ", coins[i]);
	}
    }

    printf("\nTotal coins needed: %d\n", coinCount);
    free(coins); 

getch();
}
