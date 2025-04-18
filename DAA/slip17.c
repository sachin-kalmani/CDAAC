#include<stdio.h>
#include <stdbool.h>
#define NODE 6

int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0, 0},
   {1, 0, 0, 1, 1, 0},
   {1, 0, 0, 1, 0, 1},
   {1, 1, 1, 0, 1, 1},
   {0, 1, 0, 1, 0, 1},
   {0, 0, 1, 1, 1, 0}
};

void graphColoring() {
   int color[NODE];
   color[0] = 0;
   int i,u,v;    //Assign first color for the first node
   bool colorUsed[NODE];    //Used to check whether color is used or not

   for(i = 1; i<NODE; i++)
      color[i] = -1;    //initialize all other vertices are unassigned

   for(i = 0; i<NODE; i++)
      colorUsed[i] = false;    //initially any colors are not chosen
         
   for(u = 1; u<NODE; u++) {    //for all other NODE - 1 vertices
      for(v = 0; v<NODE; v++) {
         if(graph[u][v]){
            if(color[v] != -1)    //when one color is assigned, make it unavailable
               colorUsed[color[v]] = true;
         }
     }

     int col;
     for(col = 0; col<NODE; col++)
        if(!colorUsed[col])    //find a color which is not assigned
           break;
         
     color[u] = col;    //assign found color in the list
         
     for(v = 0; v<NODE; v++) {    //for next iteration make color availability to false
        if(graph[u][v]) {
           if(color[v] != -1)
              colorUsed[color[v]] = false;
        }
     }  
  }
   
  for(u = 0; u<NODE; u++)
//     cout <<"Color: " << u << ", Assigned with Color: " <<color[u] <<endl;
     printf("Color: %d, Assigned with Color: %d\n",u,color[u]);
}

main() {
   graphColoring();
}
