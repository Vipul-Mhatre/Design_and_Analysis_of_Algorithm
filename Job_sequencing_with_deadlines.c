#include <stdio.h>
#include <conio.h>
#define MAX_JOBS 10

struct Job {
    int id;
    int deadline;
    int profit;
};

void jobSequence(struct Job jobs[], int n) {
    int i, j, *slot;
    int maxDeadline = 0;
    for (i = 0; i < n; i++) {
	if (jobs[i].deadline > maxDeadline)
	    maxDeadline = jobs[i].deadline;
    }

     *slot = (int*)malloc(maxDeadline * sizeof(int));
    if (slot == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%d ", jobs[slot[i]].id);
    }
    printf("\n");

    free(slot);
}

int main() {
    int n, i;
    struct Job jobs[MAX_JOBS];

    clrscr();
    printf("\n name:-");
    printf("\nEnter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter job deadlines and profits:\n");
    for (i = 0; i < n; i++) {
        printf("Job %d (deadline profit): ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    jobSequence(jobs, n);

    getch(); 
    return 0;
}