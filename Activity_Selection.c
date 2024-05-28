#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    int choice, n, *s, *f, i, j;
    clrscr();
    do {
        printf("1. Enter activities\n");
        printf("2. Solve Activity Selection Problem\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number of activities: ");
                scanf("%d", &n);

                s = (int *)malloc(n * sizeof(int));
                f = (int *)malloc(n * sizeof(int));

                if (s == NULL || f == NULL) {
                    printf("Memory allocation failed!\n");
                    exit(1);
                }

                printf("\nEnter start and finish times for each activity:\n");
                for (i = 0; i < n; i++) {
                    printf("Activity %d: ", i + 1);
                    scanf("%d %d", &s[i], &f[i]);

                    if (s[i] >= f[i]) {
                        printf("Invalid input: Start time must be before finish time.\n");
                        i--;
                    }
                }
                break;

            case 2:
                if (s == NULL || f == NULL) {
                    printf("Please enter activities first (option 1).\n");
                } else {
                    printf("\nFollowing activities are selected:\n");

                    i = 0;
                    printf("%d ", i);

                    for (j = 1; j < n; j++) {
                        if (s[j] >= f[i]) {
                            printf("%d ", j);
                            i = j;
                        }
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);
    if (s != NULL) {
        free(s);
    }
    if (f != NULL) {
        free(f);
    }

    return 0;
}
