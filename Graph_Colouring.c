#include <stdio.h>
#include <conio.h>
#define V 10
#define true 1
#define false 0
typedef int bool;

void printSolution(int color[], int n) {
    int i;
    printf("Coloring of vertices: \n");
    for (i = 0; i < n; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

bool isSafe(int v, int graph[V][V], int color[], int c, int n) {
    int i;
    for (i = 0; i < n; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoring(int graph[V][V], int m, int n, int color[], int v) {
    int c, i;
    if (v == n)
        return true;
    for (c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            if (graphColoring(graph, m, n, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void main() {
    int n, i, j, m;
    int graph[10][10];
    int color[10] = {0};
    clrscr();
    printf("Enter the number of vertices (maximum %d): ", V);
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &graph[i][j]);
	}
    }
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (!graphColoring(graph, m, n, color, 0)) {
	printf("No feasible solution exists\n");
	return 1;
    }
    printSolution(color, n);
getch();
}
