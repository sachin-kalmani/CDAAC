//Write a program in C/C++/ Java to implement Strassen"s Matrix multiplication
#include<stdio.h>
#include<stdlib.h>

int SIZE=2;
//strassen multiplication
void strassenMultiplication(int result[SIZE][SIZE],int a[SIZE][SIZE],int b[SIZE][SIZE])
{
	int p,q,r,s,t,u,v;
	p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
	q = (a[1][0] + a[1][1]) * (b[0][0]);
	r =  a[0][0] * (b[0][1] - b[1][1]);
	s =  a[1][1] * (b[1][0] - b[0][0]);
	t =	(a[0][0] + a[0][1]) * b[1][1];
	u =	(a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
	v =	(a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
	
	result[0][0] = p + s -t + v;
	result[0][1] = r + t;
	result[1][0] = q + s;
	result[1][1] = p + r - q + u;
}

//display
void printArray(int array1[SIZE][SIZE],int SIZE){
	int i,j;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			printf("%d ",array1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//main
void main()
{
	int result[2][2];
	int i,j;
	int size=2;
	int array1[2][2]={{12,34},{22,10}};
	int array2[2][2]={{3,4},{2,1}};
	printf("Array 1\n");
	printArray(array1,size);
	printf("Array 2\n");
	printArray(array2,size);
	strassenMultiplication(result,array1,array2);
	printf("Resultant Array\n");
	printArray(result,size);
}
