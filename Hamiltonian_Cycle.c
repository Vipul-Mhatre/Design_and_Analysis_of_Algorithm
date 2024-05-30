#include <stdio.h>
#define V 5
#define true 1
#define false 0

typedef int bool;

bool isSafe(int v, int graph[V][V], int path[], int pos) {
    int i;
    if (!graph[path[pos - 1]][v])
        return false;
    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    int v;
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        return false;
    }
    for (v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void main() {
    int graph[V][V];
    int path[V];
    int i, j;
    path[0] = 0;
    
    clrscr();
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++){
            scanf("%d", &graph[i][j]);
        }

    if (!hamCycleUtil(graph, path, 1)) {
	printf("No Hamiltonian Cycle exists\n");
	return 0;
    }

    printf("Hamiltonian Cycle exists\n");
getch();
}