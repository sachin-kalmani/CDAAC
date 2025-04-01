//15 Write a program in C/C++/ Java to determine if a given graph is a Hamiltonian cycle
//or not
#include <stdio.h>
#define NODE 5
int graph[NODE][NODE] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 1},
   {0, 1, 1, 1, 0},
};
int path[NODE];
// Function to display the Hamiltonian cycle
void displayCycle() {
	int i;
   printf("Cycle Found: ");
   for (i = 0; i < NODE; i++)
      printf("%d ", path[i]);
   // Print the first vertex again
   printf("%d\n", path[0]);
}
// Function to check if adding vertex v to the path is valid
int isValid(int v, int k) {
	int i;
   // If there is no edge between path[k-1] and v
   if (graph[path[k - 1]][v] == 0)
      return 0;
   // Check if vertex v is already taken in the path
   for (i = 0; i < k; i++)
      if (path[i] == v)
         return 0;
   return 1;
}
// Function to find the Hamiltonian cycle
int cycleFound(int k) {
   // When all vertices are in the path
   int v;
   if (k == NODE) {
      // Check if there is an edge between the last and first vertex
      if (graph[path[k - 1]][path[0]] == 1)
         return 1;
      else
         return 0;
   }
   // Try adding each vertex (except the starting point) to the path
   for (v = 1; v < NODE; v++) {
      if (isValid(v, k)) {
         path[k] = v;
         if (cycleFound(k + 1) == 1)
            return 1;
         // Backtrack: Remove v from the path
         path[k] = -1;
      }
   }
   return 0;
}
// Function to find and display the Hamiltonian cycle
int hamiltonianCycle() {
	int i;
   for (i = 0; i < NODE; i++)
      path[i] = -1;
   // Set the first vertex as 0
   path[0] = 0;
   if (cycleFound(1) == 0) {
      printf("Solution does not exist\n");
      return 0;
   }
   displayCycle();
   return 1;
}
int main() {
   hamiltonianCycle();
   return 0;
}
