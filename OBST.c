#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define MAX_KEYS 10

float sum(float freq[], int i, int j) {
    float s = 0;
    int k;
    for (k = i; k <= j; k++)
        s += freq[k];
    return s;
}

float optimalBSTCost(float freq[], int n) {
    float cost[50][50], c;
    int i, L, j, r; 
    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];
    
    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L + 1; i++) {
            j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (r = i; r <= j; r++) {
                c = ((r > i) ? cost[i][r - 1] : 0) +
                    ((r < j) ? cost[r + 1][j] : 0) +
                    sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

void main() {
    int n, i;
    float cost;
    float freq[MAX_KEYS];
    clrscr();
    
    printf("Enter the number of keys (up to %d): ", MAX_KEYS);
    scanf("%d", &n);
    
    printf("Enter the probabilities of each key:\n");
    for (i = 0; i < n; i++) {
        printf("Probability for key %d: ", i + 1);
        scanf("%f", &freq[i]);
    }

    cost = optimalBSTCost(freq, n);
    printf("Optimal BST cost: %f\n", cost);
    
getch();
}
