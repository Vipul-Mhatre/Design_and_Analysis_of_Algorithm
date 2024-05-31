#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define V_MAX 20

int i,j,count,v;
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index,v;
    for (v = 0; v < V; v++) {
	if (mstSet[v] == 0 && key[v] < min) {
	    min = key[v];
	    min_index = v;
	}
    }
    return min_index;
}

void printMST(int parent[], int graph[V_MAX][V_MAX], int V) {
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++) {
	printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V_MAX][V_MAX], int V) {
    int parent[V_MAX];
    int key[V_MAX];
    int mstSet[V_MAX];
    for (i = 0; i < V; i++) {
	key[i] = INT_MAX;
	mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (count = 0; count < V - 1; count++) {
	int u = minKey(key, mstSet, V);
	mstSet[u] = 1;
	for (v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int V;
     int graph[V_MAX][V_MAX];
    clrscr(); 
    printf("Enter number of vertices (maximum %d): ", V_MAX);
    scanf("%d", &V);
    if (V <= 0 || V > V_MAX) {
	printf("Invalid input\n");
	return 1;
    }
    printf("Enter adjacency matrix:\n");

    for (i = 0; i < V; i++) {
	for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);
    getch(); 
    return 0;
}
