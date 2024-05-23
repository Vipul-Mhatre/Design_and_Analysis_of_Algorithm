#include <stdio.h>
#include <conio.h>

int max(int a, int b) {
 if(a>b)
 {
 return a;
 }
 return b;
}

int knapsack(int W, int wt[], int val[], int n) {
 int i, w;
 int K[100][100];
 for (i = 0; i <= n; i++) {
 for (w = 0; w <= W; w++) {
 if (i == 0 || w == 0)
 K[i][w] = 0;
 else if (wt[i - 1] <= w)
 K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 
1]], K[i - 1][w]);
 else
 K[i][w] = K[i - 1][w];
 }
 }
 return K[n][W];
}

void main() {
 int val[100], wt[100], W, n,i,result;
 clrscr();
 printf("Enter the number of items: ");
 scanf("%d", &n);
 printf("Enter the knapsack capacity: ");
 scanf("%d", &W);
 printf("Enter the values of items:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &val[i]);
 }
 printf("Enter the weights of items:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &wt[i]);
 }
 
  result = knapsack(W, wt, val, n);
 printf("Maximum value that can be obtained is %d\n", result);
getch();
}