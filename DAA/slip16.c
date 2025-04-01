#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int graph[MAX][MAX];

// Function to find the nearest neighbor
void tspNearestNeighbor() {
    int visited[MAX] = {0};  
    int path[MAX];            
    int cost = 0, current = 0, next, minCost;
	int i,j;
    visited[current] = 1;
    path[0] = current;

    for (i = 1; i < n; i++) {
        minCost = INT_MAX;
        next = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[current][j] < minCost && graph[current][j] > 0) {
                minCost = graph[current][j];
                next = j;
            }
        }

        if (next == -1) return; 

        visited[next] = 1;
        path[i] = next;
        cost += minCost;
        current = next;
    }

    cost += graph[current][0]; // Return to the starting city

    printf("Minimum cost: %d\nBest path: ", cost);
    for (i = 0; i < n; i++) printf("%d -> ", path[i]);
    printf("0\n"); 
}

int main() {
    n = 4; // Number of cities
	int i,j;
    // Predefined cost matrix
    int tempGraph[MAX][MAX] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = tempGraph[i][j];

    tspNearestNeighbor();

    return 0;
}

