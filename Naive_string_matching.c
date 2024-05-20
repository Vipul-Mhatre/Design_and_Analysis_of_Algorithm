#include <stdio.h>
#include <conio.h>
#include <string.h>

void NaiveSM(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int found = 0;

    for (i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == M) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Pattern not found\n");
    }
}

void main() {
    char text[100], pattern[100];
    clrscr();
    printf("Enter the text: ");
    scanf("%[^\n]", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    NaiveSM(pattern, text);

    getch();
}
