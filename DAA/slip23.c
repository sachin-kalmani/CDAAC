#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visited[MAX_NODES];          // Track visited nodes
int n;                           // Number of nodes

// BFS function to classify nodes
void find_nodes(int start) {
    int queue[MAX_NODES], front = 0, rear = 0;
    int live_nodes[MAX_NODES], dead_nodes[MAX_NODES], e_nodes[MAX_NODES];
    int live_count = 0, dead_count = 0, e_count = 0;
	int i;
    // Initialize all nodes as unvisited
    for (i = 0; i < n; i++) visited[i] = 0;

    // Start BFS from the given node
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++]; // Current E-Node
        e_nodes[e_count++] = node;

        // Process all adjacent nodes
        for (i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    // Classify nodes
    for (i = 0; i < n; i++) {
        if (visited[i])
            live_nodes[live_count++] = i;
        else
            dead_nodes[dead_count++] = i;
    }

    // Print results
    printf("Live Nodes: ");
    for (i = 0; i < live_count; i++) printf("%d ", live_nodes[i]);
    printf("\n");

    printf("E Nodes: ");
    for (i = 0; i < e_count; i++) printf("%d ", e_nodes[i]);
    printf("\n");

    printf("Dead Nodes: ");
    for (i = 0; i < dead_count; i++) printf("%d ", dead_nodes[i]);
    printf("\n");
}

int main() {
    int edges, start_node;
	int i,j;
    // Input number of nodes and edges
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = 0;

    // Input edges
    printf("Enter edges (u v) format:\n");
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Directed graph
    }

    // Input start node
    printf("Enter start node: ");
    scanf("%d", &start_node);

    // Find and classify nodes
    find_nodes(start_node);

    return 0;
}

