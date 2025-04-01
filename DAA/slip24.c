#include <stdio.h>
#include <limits.h>

#define MAX 4  // Number of cities

int graph[MAX][MAX] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int min_cost = INT_MAX, best_path[MAX];

// Function to find the minimum cost path using recursion
void tsp(int node, int visited[], int path[], int level, int cost) {
	int i;
    if (level == MAX) {  // All cities visited
        cost += graph[node][0];  // Return to start city
        if (cost < min_cost) {    
            min_cost = cost;
            for (i = 0; i < MAX; i++) best_path[i] = path[i];
        }
        return;
    }

    for (i = 0; i < MAX; i++) {
        if (!visited[i] && graph[node][i] > 0) {
            visited[i] = 1;
            path[level] = i;
            tsp(i, visited, path, level + 1, cost + graph[node][i]);
            visited[i] = 0;  // Backtrack
        }
    }
}

int main() {
    int visited[MAX] = {0}, path[MAX],i;
    visited[0] = 1;  // Start from city 0
    path[0] = 0;

    tsp(0, visited, path, 1, 0);

    printf("Minimum cost: %d\nBest path: ", min_cost);
    for (i = 0; i < MAX; i++) printf("%d -> ", best_path[i]);
    printf("0\n"); // Returning to start city

    return 0;
}

