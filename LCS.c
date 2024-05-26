#include <stdio.h>
#include <conio.h>
#include <string.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int lcsLength(char* text, char* pattern, int n, int m, char *lcs) {
    int L[101][101]; 
    int i, j,index;

    for (i = 0; i <= n; i++) {
	for (j = 0; j <= m; j++) {
	    if (i == 0 || j == 0)
		L[i][j] = 0;
	    else if (text[i - 1] == pattern[j - 1])
		L[i][j] = L[i - 1][j - 1] + 1;
	    else
		L[i][j] = max(L[i - 1][j], L[i][j - 1]);
	}
    }
     index = L[n][m];
    lcs[index] = '\0'; // Null-terminate the string
    i = n;
    j = m;
    while (i > 0 && j > 0) {
	if (text[i - 1] == pattern[j - 1]) {
	    lcs[--index] = text[i - 1];
	    i--;
	    j--;
	} else if (L[i - 1][j] > L[i][j - 1]) {
	    i--;
	} else {
	    j--;
	}
    }
    return L[n][m];
}

void main() {
    int n, m;
    char text[101], pattern[101], lcs[101];
    clrscr();
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);
    n = strlen(text);
    m = strlen(pattern);
    printf("Length of Longest Common Subsequence is %d\n", lcsLength(text, pattern, n, m, lcs));
    printf("Longest Common Subsequence: %s\n", lcs);
getch();
}
