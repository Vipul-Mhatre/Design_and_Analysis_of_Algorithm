#include <stdio.h>
#include <conio.h>

#define N_MAX 20

int board[N_MAX][N_MAX];
int found_solution = 0;

int isSafe(int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

int solveNQueensUtil(int col, int n) {
    int i, j;
    if (col >= n) {
        printf("Solution:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            found_solution |= solveNQueensUtil(col + 1, n);
            board[i][col] = 0; 
        }
    }
    return found_solution;
}

void solveNQueens(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueensUtil(0, n)) {
        printf("Solution does not exist \n");
        return;
    }
}

int main() {
    int n;

    printf("Enter the number of queens (<= %d): ", N_MAX);
    scanf("%d", &n);

    if (n <= 0 || n > N_MAX) {
        printf("Invalid input \n");
        return 1;
    }

    solveNQueens(n);
    getch(); 
    return 0;
}
