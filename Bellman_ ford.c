#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define MAX_VERTICES 100

void TotalDist(int dist[], int n) {
    int i;
    printf("Vertex Distance from Source: \n");
    for (i=0;i<n;++i) {
        if (dist[i]==INT_MAX)
            printf("%d \tINF\n", i);
        else
            printf("%d \t%d\n", i, dist[i]);
    }
}

void bellmanFord(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
    int dist[MAX_VERTICES];
    int i,u,v;
    
    for (i=0; i<V;i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;
    for (i=1;i<=V-1; i++) {
        for (u=0;u<V; u++) {
            for (v=0;v<V;v++) {
                if (graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    
    for (u=0;u<V; u++) {
        for (v=0;v<V; v++) {
            if (graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle.\n");
		return;
	    }
	}
    }

    TotalDist(dist, V);
}

int main() {
    int V, E, i, j, source;
    int u, v, weight;
    int graph[MAX_VERTICES][MAX_VERTICES];
    clrscr();
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&V,&E);

    for (i=0; i<V; i++) {
	    for (j=0; j<V; j++) 
        {
	        graph[i][j] = INT_MAX;
	    }
    }

    printf("Enter source, destination, and weight for each edge: \n");
    for (i = 0; i<E; i++) {
	scanf("%d %d %d", &u, &v, &weight);
	graph[u][v]=weight;
    }

    printf("Enter the source vertex: \n");
    scanf("%d",&source);

    bellmanFord(graph, V, source);

    getch();
}
