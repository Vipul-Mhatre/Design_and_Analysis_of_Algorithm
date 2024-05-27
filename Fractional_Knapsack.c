#include<stdio.h>
#include<conio.h>

void knapsack(int n, float weight[], float profit[], float capacity) 
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
    x[i] = 0.0;
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
        break;
        else {
        x[i] = 1.0;
        tp = tp + profit[i];
        u = u - weight[i];
        }
    }

    if (i < n)
    x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);
    printf("\nMaximum energy: %f", tp);
}

int main() {
 float weight[20], nutval[20], capacity;
 int num, i, j;
 float ratio[20], temp;
 clrscr();
 printf("\nEnter the no. of fruits: ");
 scanf("%d", &num);

 printf("\nEnter the weight of each fruit: ");
 for (i = 0; i < num; i++) {
    scanf("%f", &weight[i]);
 }

 printf("\nEnter the nutriotional value of each fruit: ");
 for (i = 0; i < num; i++) {
    scanf("%f", &nutval[i]);
 }
 printf("\nEnter the capacity of backpack: ");
 scanf("%f",&capacity);

 for (i = 0; i < num; i++) {
    ratio[i] = nutval[i] / weight[i];
 }

 for (i = 0; i < num; i++) {
    for (j = i + 1; j < num; j++) {
        if (ratio[i] < ratio[j]) {
        temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;

        temp = weight[j];
        weight[j] = weight[i];
        weight[i] = temp;

        temp = nutval[j];
        nutval[j] = nutval[i];
        nutval[i] = temp;
        }
    }
 }

 knapsack(num, weight, nutval, capacity);

 getch();
}
