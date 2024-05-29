#include <stdio.h>
#include <limits.h>
#include <conio.h>

int i,len,k;
int matrixChainOrder(int dims[], int n) {
    int dp[100][100]; 
    for (i=1; i<n; i++)
	dp[i][i]=0;
    for (len=2; len<n; len++) {
	for (i=1; i<n-len+1; i++) {
	    int j=i+len-1;
	    dp[i][j]=INT_MAX;
	    for (k=i; k <= j-1; k++) {
		int cost=dp[i][k]+dp[k+1][j]+dims[i-1]*dims[k]*dims[j];
		if (cost<dp[i][j])
                    dp[i][j]=cost;
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    int n,dims[101],minMultiplications;
    clrscr();
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    printf("Enter the dimensions of the matrices : ");
    for (i=0; i <= n; i++) {
	scanf("%d", &dims[i]);
    }
     minMultiplications=matrixChainOrder(dims, n+1);

    printf("Minimum number of scalar multiplications: %d\n", minMultiplications);
getch();
    return 0;
}
