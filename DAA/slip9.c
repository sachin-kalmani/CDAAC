//9 Write a program in C/C++/ Java to implement optimal binary search tree and also
//calculate the best case and worst case complexity.

#include <stdio.h>
#define INT_MAX 999

int sum(int freq[], int low, int high) {    //sum of frequency from low to high range
   int sum = 0;
   int k;
   for (k = low; k <=high; k++)
      sum += freq[k];
   return sum;
}

int minCostBST(int keys[], int freq[], int n) {
   int cost[n][n];
   int i,length,r;
   for (i = 0; i < n; i++)    //when only one key, move along diagonal elements
      cost[i][i] = freq[i];

   for (length=2; length<=n; length++) {
      for (i=0; i<=n-length+1; i++) {    //from 0th row to n-length+1 row as i
         int j = i+length-1;
         cost[i][j] = INT_MAX;    //initially store to infinity

         for (r=i; r<=j; r++) {
            //find cost when r is root of subtree
            int c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+sum(freq, i, j);
            if (c < cost[i][j])
               cost[i][j] = c;
         }
      }
   }
   return cost[0][n-1];
}

int main() {
   int keys[] = {10, 12, 20};
   int freq[] = {34, 8, 50};
   int n = 3;
   printf("Cost of Optimal BST is: %d",minCostBST(keys, freq, n));
}
