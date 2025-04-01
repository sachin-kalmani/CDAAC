//Write a program in C/C++/ Java to implement Sum of Subset by Backtracking

#include <stdio.h>
#define SIZE 7
void displaySubset(int subSet[], int size) {
	int i;
   for(i = 0; i < size; i++) {
      printf("%d  ", subSet[i]);
   }
   printf("\n");
}
void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum) {
	int i;
   if( total == sum) {
      //print the subset 
      displaySubset(subSet, subSize);  
      //for other subsets
      if (subSize != 0)
         subsetSum(set,subSet,n,subSize-2,total-set[nodeCount],nodeCount+1,sum);     
      return;
   }else {
      //find node along breadth 
      for(i = nodeCount; i < n; i++ ) {     
         subSet[subSize] = set[i];
          //do for next node in depth
         subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum);    
      }
   }
}
void findSubset(int set[], int size, int sum) {
   //create subset array to pass parameter of subsetSum
   int subSet[size];     
   subsetSum(set, subSet, size, 0, 0, 0, sum);
}
int main() {
   int weights[] = {1, 9, 7, 5, 18, 12, 20, 15};
   int size = SIZE;
   findSubset(weights, size, 35);
   return 0;
}
